//Q. Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
//Note: You can only move either down or right at any point in time.

class Solution {
public:

//just for logic related reference.

    // int recur(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp)
    // {
    //     int left, up;
    //     //bc
    //     if(row==0 && col==0) return grid[row][col];
    //     //when not bc
    //     if(row<0 || col<0) return 1e9; 
    //     if(dp[row][col]!= -1) return dp[row][col];
    //     up = recur(row-1, col, grid, dp);
    //     left = recur(row, col-1, grid, dp);
    //     return dp[row][col] = grid[row][col] + min(left, up);
    // }

    int minPathSum(vector<vector<int>>& grid) {
        //greedy not possible, as in greedy you would go down but that wont work
        int m = grid.size();
        int n = grid[0].size();

        //initialization of space
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        vector<int> prev(n, 0);
        vector<int> curr(n, 0);

        //we will need a prevRow and current row array
        //MY SHORTCUT--> replace dp[row] with curr and dp[row-1] with prev
        for(int row = 0; row < m; row++)
        {
            for(int col = 0; col < n; col++)
            {
                if(row==0 && col==0) 
                {
                    curr[0] = grid[0][0];
                }
                else if(row==0) 
                {
                    curr[col] = grid[row][col] + curr[col-1];
                }
                else if(col == 0) 
                {
                    curr[col] = grid[row][col] + prev[col];  
                }
                else
                {
                curr[col] = grid[row][col] + min(prev[col], curr[col-1]);
                }
            }
            prev = curr;
        }
        
        return prev[n-1];
    }
};
