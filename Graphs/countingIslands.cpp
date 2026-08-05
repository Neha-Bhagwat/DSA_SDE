class Solution {
public:

    void dfs(vector<vector<char>> & grid, vector<vector<int>> &vis, int row, int col)
    {
        int m = grid.size(), n = grid[0].size();
        // mark visited
        vis[row][col] = 1;
        // make delrow and delcol
        vector<int> delrow = {0,0,-1,1};
        vector<int> delcol = {-1,1,0,0};
        // iterate over nrow and ncol
        for(int i = 0; i < 4; i++)
        {
            int nrow = delrow[i]+row;
            int ncol = delcol[i]+col;

            // if not visited and inside the bounds, run dfs again
            if(nrow>=0 && nrow<m && ncol>=0 && ncol<n && !vis[nrow][ncol] && grid[nrow][ncol] == '1') dfs(grid, vis, nrow, ncol);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(); 
        int count = 0;
        vector<vector<int>> vis(m, vector<int>(n,0));

        for(int i = 0; i < m;i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(vis[i][j] == 0 && grid[i][j] == '1') 
                {   
                    dfs(grid, vis, i, j);
                    count++;
                }
            }
        }
        return count;
    }
};
