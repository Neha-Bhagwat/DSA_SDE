// 1020. Number of Enclaves
// You are given an m x n binary matrix grid, where 0 represents a sea cell and 1 represents a land cell.
// A move consists of walking from one land cell to another adjacent (4-directionally) land cell or walking off the boundary of the grid.
// Return the number of land cells in grid for which we cannot walk off the boundary of the grid in any number of moves.

// Example 1:
// Input: grid = [[0,0,0,0],[1,0,1,0],[0,1,1,0],[0,0,0,0]]
// Output: 3
// Explanation: There are three 1s that are enclosed by 0s, and one 1 that is not enclosed because its on the boundary.

// Example 2:
// Input: grid = [[0,1,1,0],[0,0,1,0],[0,0,1,0],[0,0,0,0]]
// Output: 0
// Explanation: All 1s are either on the boundary or can reach the boundary.

// Constraints:
// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 500
// grid[i][j] is either 0 or 1.

class Solution {
public:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, int row, int col)
    {
        int m = grid.size(), n = grid[0].size();
        // check for all adjacent
        vector<int> drow = {-1, 1, 0, 0};
        vector<int> dcol = {0, 0, -1, 1};
        vector<int> nrow(4,0);
        vector<int> ncol(4,0);
        vis[row][col] = 1;

        cout<<row<<" "<<col<<endl;
        // get values of nrow and ncol
        for(int i = 0 ; i < 4; i++)
        {
            nrow[i] = drow[i] + row;
            ncol[i] = dcol[i] + col;
        }

        for(int i = 0; i < 4; i++)
        {
            int newR = nrow[i], newC = ncol[i];
            //do dfs if not visited, if it is a land cell
            if(newR>0 && newC > 0 && newR < m && newC < n && !vis[newR][newC] && grid[newR][newC] == 1)
            {
                dfs(grid, vis, newR, newC);
            }
        }

        // if they are 1s, and not visited go dfs
    }
    int numEnclaves(vector<vector<int>>& grid) 
    {
        // make visited array
        int m = grid.size(), n = grid[0].size(), ans = 0;
        vector<vector<int>> vis(m, vector<int>(n,0));
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                bool boundary = false;
                // mark all 0s visited
                if(grid[i][j] == 0)
                { vis[i][j] = 1;
                }
                // boundary condition
                else if(i == 0 || i == m-1 || j == 0 || j == n-1) boundary = true;
                // if boundary then dfs 
                if(boundary == true && vis[i][j] == 0 && grid[i][j] == 1) 
                {   
                    dfs(grid, vis, i , j);
                }
            }
        }
            
        //count num of not visited 1s
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(!vis[i][j]) ans++;
            }
        }
        return ans;
    }   

};
