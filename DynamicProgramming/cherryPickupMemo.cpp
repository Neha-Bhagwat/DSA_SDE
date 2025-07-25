//https://www.naukri.com/code360/problems/ninja-and-his-friends_3125885?leftPanelTabValue=SUBMISSION
//Ninja has a 'GRID' of size 'R' X 'C'. Each cell of the grid contains some chocolates. Ninja has two friends Alice and Bob, and he wants to collect as many chocolates as possible with the help of his friends.
//Example:
// Input: ‘R’ = 3, ‘C’ = 4
//        ‘GRID’ = [[2, 3, 1, 2], [3, 4, 2, 2], [5, 6, 3, 5]]
// Output: 21
// Initially Alice is at the position (0,0) he can follow the path (0,0) -> (1,1) -> (2,1) and will collect 2 + 4 + 6 = 12 chocolates.
// Initially Bob is at the position (0, 3) and he can follow the path (0, 3) -> (1,3) -> (2, 3) and will colllect 2 + 2 + 5 = 9 chocolates.
// Hence the total number of chocolates collected will be 12 + 9 = 21. there is no other possible way to collect a greater number of chocolates than 21.

Initially, Alice is in the top-left position i.e. (0, 0), and Bob is in the top-right place i.e. (0, ‘C’ - 1) in the grid. Each of them can move from their current cell to the cells just below them. When anyone passes from any cell, he will pick all chocolates in it, and then the number of chocolates in that cell will become zero. If both stay in the same cell, only one of them will pick the chocolates in it.

If Alice or Bob is at (i, j) then they can move to (i + 1, j), (i + 1, j - 1) or (i + 1, j + 1). They will always stay inside the ‘GRID’.

Your task is to find the maximum number of chocolates Ninja can collect with the help of his friends by following the above rules.

#include <bits/stdc++.h> 

int recur(int row, int col1, int col2, int r, int c, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp) 
{
    //bc
    //oob
    int maxi = INT_MIN;
    if(col1>c-1 || col1<0 || col2>c-1 || col2<0)
    {
        return -1e8;
    }

    //end case
    if(row == r-1) 
    {
        if(col1 == col2) return grid[row][col1];
        else return grid[row][col1] + grid[row][col2];
    } 

    if(dp[row][col1][col2] != -1) return dp[row][col1][col2];
    //normally, we move the 2 people
    for(int i = -1 ; i<=1; i++)
    {
        for(int j = -1; j<=1; j++)
        {
            if(col1==col2) maxi = max(maxi,grid[row][col1] + recur(row+1, col1+i, col2+j, r, c, grid, dp));
            else maxi = max(maxi, grid[row][col1]+grid[row][col2] + recur(row+1, col1+i, col2+j, r, c, grid, dp));
        }
    }

    return dp[row][col1][col2] = maxi;
}

int maximumChocolates(int r, int c, vector<vector<int>> &grid) 
{
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    return recur(0,0,c-1,r,c,grid, dp);
}
