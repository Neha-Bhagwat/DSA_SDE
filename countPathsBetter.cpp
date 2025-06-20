class Solution {
public:
//here, we convert the same recursive solution into a dynamic programming solution. we reuse the values if they are already stored in the array as needed.
//TC-> O(m*n) SC-> O(m*n)
    int countPaths(int m, int n, int i, int j, vector<vector<int>> dp)
    {
        //base case1
        if(i == m-1 && j == n-1)
        {
            return 1;
        }
        else if(i >= m || j >=n)
        {
            return 0;
        }
        //case where the value is stored already
        if(dp[i][j]!=-1) return dp[i][j];
        //recursion
        else
        {
            return dp[i][j] = countPaths(m,n,i+1,j,dp) + countPaths(m,n,i,j+1,dp);
        }
    }

    int uniquePaths(int m, int n) 
    {
        vector<vector<int>> dp(m, vector<int>(n,-1));
        return  countPaths(m, n, 0, 0,dp);
    }
};
