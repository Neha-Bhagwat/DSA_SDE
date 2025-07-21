class Solution {
public:
//we keep this recursion code in comments so that we can take the help of this while writing the tabulation.
    // int pathsRecur(int x, int y, int m, int n, vector<vector<int>> &dp)
    // {
    //     int answer;
    //     //bc
    //     if(x == m-1 && y == n-1)
    //     {
    //         return 1;
    //     }

    //     //bc 2
    //     if(x > m-1 || y > n-1)
    //     {
    //         return 0;
    //     }  

    //     if(dp[x][y] != -1) return dp[x][y];
        
    //     return dp[x][y] = pathsRecur(x, y+1, m, n, dp) + pathsRecur(x+1, y, m, n, dp);
    // }

//now we want to optimize space. we need 2 things, right and bottom.
//we need the right value while we iterate through j. then, bottom remains fixed
//bottom changes when we change the i.

//we need a 1d array for that
//replace dp[i] with current and dp[i+1] as prevRow
    int uniquePaths(int m, int n) 
    {
        vector<vector<int>> dp(m, vector<int>(n, 0));
        vector<int> prevRow(n, 0);
        vector<int> curr(n, 0);
        for(int i = m-1; i>=0; i--)
        {
            for(int j = n-1; j>=0; j--)
            {
                if(i == m-1 && j == n-1) curr[j] = 1;
                else if(i == m-1) curr[j] = curr[j+1];
                else if(j == n-1) curr[j] = prevRow[j];
                else curr[j] = prevRow[j] + curr[j+1];
            }
            //replace prevRow and curr
            prevRow = curr;
        }

        return curr[0];
    }

};
