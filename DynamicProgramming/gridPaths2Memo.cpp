class Solution {
public:
    int recurFunc(int row, int col, vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp)
    {
        //bc1 
        if(row == 0 && col == 0 && obstacleGrid[0][0] == 0) return 1;
        //bc2
        if(row<0 || col<0) return 0;
        if(obstacleGrid[row][col] == 1) return 0;

        //normal case
        if(dp[row][col] != -1) return dp[row][col];
        return dp[row][col] = recurFunc(row-1, col, obstacleGrid, dp) + recurFunc(row, col-1, obstacleGrid, dp);
    }


    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        int m = obstacleGrid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return recurFunc(n-1, m-1, obstacleGrid, dp);
    }
};
