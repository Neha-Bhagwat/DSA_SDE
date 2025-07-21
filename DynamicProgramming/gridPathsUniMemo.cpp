class Solution {
public:
    int pathsRecur(int x, int y, int m, int n, vector<vector<int>> &dp)
    {
        int answer;
        //bc
        if(x == m-1 && y == n-1)
        {
            return 1;
        }

        //bc 2
        if(x > m-1 || y > n-1)
        {
            return 0;
        }  

        if(dp[x][y] != -1) return dp[x][y];
        
        return dp[x][y] = pathsRecur(x, y+1, m, n, dp) + pathsRecur(x+1, y, m, n, dp);
    }
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return pathsRecur(0,0,m,n, dp);
    }
};
