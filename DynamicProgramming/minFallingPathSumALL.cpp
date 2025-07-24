//Given an n x n array of integers matrix, return the minimum sum of any falling path through matrix.

//A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position (row, col) will be (row + 1, col - 1), (row + 1, col), or (row + 1, col + 1).

class Solution {
public:
    // int pathRecur(int row, int col, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
    //     //bc
    //     if(row == 0 && col >= 0 && col <= matrix.size()-1) return matrix[0][col];
    //     if(col < 0 || col > matrix.size()-1) return 1e9;

    //     if(dp[row][col] != -1) return dp[row][col];
    //     //now normal case
    //     int left = matrix[row][col] + pathRecur(row-1, col-1, matrix, dp);
    //     int up = matrix[row][col] + pathRecur(row-1, col, matrix, dp);
    //     int right = matrix[row][col] + pathRecur(row-1, col+1, matrix, dp);
       
    //     return dp[row][col] = min({left, right, up});
    // }

    //we need to store the current row and the previous one to work with this
    //replaced dp[row] with curr and dp[row-1] with prev.

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<int> curr(n,0);
        vector<int> prev(n,0);
        int mini = INT_MAX;

        //base case
        for(int i = 0; i<n; i++)
        {
            prev[i] = matrix[0][i];
        }

        //main case
        for(int row = 1; row < n; row++)
        {
            for(int col = 0; col < n; col++)
            {
                if(col==0) 
                {
                    curr[col] = matrix[row][col] + min(prev[col], prev[col+1]);
                }

                else if(col == n-1) 
                {
                    curr[col] = matrix[row][col] + min(prev[col-1], prev[col]);
                }

                else
                    curr[col] = matrix[row][col] + min({prev[col-1], prev[col], prev[col+1]});
            }
            prev = curr;
        } 
        
        for(int i = 0; i < n; i++)
        {
            mini = min(mini,prev[i]);
        }
        return mini;       
    }
};

//Recursion:
//TC-> O(3^n)
//SC-> O(n) stack space

//Memo:
//TC-> O(nxn)
//SC-> O(n) stack space + O(nxn) array

//Tabu:

//SO:
