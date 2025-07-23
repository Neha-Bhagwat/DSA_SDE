//Q. Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
//Note: You can only move either down or right at any point in time.

//first think and write down the recursive logic. then it only takes like 2 mins to add the dp logic.

class Solution {
public:
    int recur(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
        int left, up;
        //bc
        if(row==0 && col==0) return grid[row][col];
        //when not bc
        if(row<0 || col<0) return 1e9; 
        if(dp[row][col]!= -1) return dp[row][col];
        up = recur(row-1, col, grid, dp);
        left = recur(row, col-1, grid, dp);
        return dp[row][col] = grid[row][col] + min(left, up);
    }
    int minPathSum(vector<vector<int>>& grid) {
        //greedy not possible, as in greedy you would go down but that wont work
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return recur(m-1, n-1, grid, dp);
    }
};
