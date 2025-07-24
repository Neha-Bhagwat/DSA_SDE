//Q. Given a triangle array, return the minimum path sum from top to bottom.
//For each step, you may move to an adjacent number of the row below. More formally, if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.

//TC-> 2^(1+2+...+N)

class Solution {
public:
    // int minimumRecur(int row, int col, vector<vector<int>>& triangle, vector<vector<int>>& dp) 
    // {
    //     //bc
    //     if(row == triangle.size()-1)
    //         return triangle[row][col];
    //     // if(row<0 || col<0 || col>row) return 1e9; //case where col goes out two sides and row goes above
    //     //this isnt strictly necessary
    //     if(dp[row][col]  != -1) return dp[row][col];
    //     int left = triangle[row][col] + minimumRecur(row+1, col+1, triangle, dp);
    //     int right = triangle[row][col] + minimumRecur(row+1, col, triangle, dp);
    //     return dp[row][col] = min(left, right);
    // }
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n = triangle.size();
        // vector<vector<int>> dp;
        // for(int i = 0; i<n; i++)
        // {
        //     dp.push_back(vector<int>(triangle[i].size(),-1));
        // }

        //for space optimization, we need 2 1d arrays
        vector<int> prev(n, 0);
        vector<int> curr(n, 0);

        for(int i = 0; i < n; i++)
        {
            prev[i] = triangle[n-1][i];
        }
        
        //replace dp[row] with current and dp[row+1] with prev

        for(int row =n-2; row>=0; row--)
        {
            for(int col = row; col>=0; col--)
            {
                int left = triangle[row][col] + prev[col+1];
                int right = triangle[row][col] + prev[col];
                curr[col] = min(left, right);
            }
            prev = curr;
        }
        return prev[0];
    }
};

//TC->O(n*m) memoization 
//SC->O(N)+O(NxN) stack space (in memo, not in tabu)
