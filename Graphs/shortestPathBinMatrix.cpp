// 1091. Shortest Path in Binary Matrix
// Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.
// A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:
// All the visited cells of the path are 0.
// All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
// The length of a clear path is the number of visited cells of this path.

// Example 1:
// Input: grid = [[0,1],[1,0]]
// Output: 2

// Example 2:
// Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
// Output: 4

// Example 3:
// Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
// Output: -1

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        queue<pair<pair<int,int>,int>> q;
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n,0));
        if(grid[0][0] == 1) return -1;
        q.push({{0,0},1});
        vis[0][0] = 1;
        while(!q.empty())
        {
            int x = q.front().first.first, y = q.front().first.second, dis = q.front().second;
            q.pop();
            // base case
            if(x == n-1 && y == n-1) return dis;
            // otherwise, go to valid, non-visited, 8-dir neighbours with 0
            for(int dr = -1; dr < 2; dr++)
            {
                for(int dc = -1; dc < 2; dc++)
                {
                    int r = x + dr, c = y + dc;
                    if(r >= 0 && r < n && c >=0 && c < n && grid[r][c] == 0 && vis[r][c] == 0)
                    {
                        // cout<<r<<" "<<c<<" "<<dis+1<<endl;
                        // then only push
                        vis[r][c] = 1;
                        q.push({{r,c},dis+1});
                    }
                }
            }
        }
        return -1;
    }
};
