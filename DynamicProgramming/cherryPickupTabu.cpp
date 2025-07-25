#include <bits/stdc++.h> 

//int recur(int row, int col1, int col2, int r, int c, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp) 
// {
//     //bc
//     //oob
//     int maxi = INT_MIN;
//     if(col1>c-1 || col1<0 || col2>c-1 || col2<0)
//     {
//         return -1e8;
//     }

//     //end case
//     if(row == r-1) 
//     {
//         if(col1 == col2) return grid[row][col1];
//         else return grid[row][col1] + grid[row][col2];
//     } 

//     if(dp[row][col1][col2] != -1) return dp[row][col1][col2];
//     //normally, we move the 2 people
//     for(int i = -1 ; i<=1; i++)
//     {
//         for(int j = -1; j<=1; j++)
//         {
//             if(col1==col2) maxi = max(maxi,grid[row][col1] + recur(row+1, col1+i, col2+j, r, c, grid, dp));
//             else maxi = max(maxi, grid[row][col1]+grid[row][col2] + recur(row+1, col1+i, col2+j, r, c, grid, dp));
//         }
//     }

//     return dp[row][col1][col2] = maxi;
// }

int maximumChocolates(int n, int c, vector<vector<int>> &grid) 
{
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(c, vector<int>(c, -1)));
    //base case for end case
    for(int col1 = 0; col1<c; col1++)
    {
        for(int col2 = 0; col2<c; col2++)
        {
            if(col1 == col2) dp[n-1][col1][col2] = grid[n-1][col1];
            else dp[n-1][col1][col2] = grid[n-1][col1] + grid[n-1][col2];
        }
    }

                    int maxi = -1e8;


    for(int row = n-2; row>=0; row--)
    {
        for(int col1 = 0; col1<c; col1++)
        {
            for(int col2=0; col2<c; col2++)
            {
                maxi = -1e8;
                //normally, we move the 2 people
                for(int i = -1 ; i<=1; i++)
                {
                    for(int j = -1; j<=1; j++)
                    {
                        int new_col1 = col1 + i;
                        int new_col2 = col2 + j;
                        if(new_col1 >= 0 && new_col1 < c && new_col2 >= 0 && new_col2 < c)
                        {
                            int val = (col1 == col2) ? grid[row][col1] : grid[row][col1] + grid[row][col2];
                            val += dp[row+1][new_col1][new_col2];
                            maxi = max(maxi, val);
                        }
                    }
                }
                dp[row][col1][col2] = maxi;
            }
        }
    }
    
    return dp[0][0][c-1];
}
