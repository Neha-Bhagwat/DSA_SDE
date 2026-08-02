// 130. Surrounded Regions
// You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:
// Connect: A cell is connected to adjacent cells horizontally or vertically.
// Region: To form a region connect every 'O' cell.
// Surround: A region is surrounded if none of the 'O' cells in that region are on the edge of the board. Such regions are completely enclosed by 'X' cells.
// To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything.

    
// Example 1:
// Input: board = [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
// Output: [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
// Explanation:
// In the above diagram, the bottom region is not captured because it is on the edge of the board and cannot be surrounded.

// Example 2:
// Input: board = [["X"]]
// Output: [["X"]]

// Constraints:
// m == board.length
// n == board[i].length
// 1 <= m, n <= 200
// board[i][j] is 'X' or 'O'.

class Solution {
public:
    void dfs(vector<vector<char>>& board, vector<vector<int>>& vis, int row, int col)
    {
        // visit the node
        int m = board.size(), n = board[0].size();
        vis[row][col] = 1;
        // go to neighbours
        vector<int> drow = {-1, 1, 0, 0};
        vector<int> dcol = {0, 0, -1, 1};
        vector<int> nrow(4,0);
        vector<int> ncol(4,0);
        // define the row and col
        for(int i = 0; i < 4; i++)
        {
            nrow[i] = drow[i] + row;
            ncol[i] = dcol[i] + col;
        }
        for(int i = 0; i < 4; i++)
        {
            // run dfs on each if
            // they arent out of bounds and they are O
            int newRow = nrow[i], newCol = ncol[i];
            if(newRow >= 0 && newCol >= 0 && newRow < m  && newCol < n && !vis[newRow][newCol] && board[newRow][newCol] == 'O')
            {
                dfs(board, vis, newRow, newCol);
            }
        }
        
    }
    void solve(vector<vector<char>>& board) {
        // make vis matrix
        int m = board.size(), n = board[0].size();

        vector<vector<int>> vis(m, vector<int>(n, 0));

        for(int i = 0; i < m; i++)
        {
            for(int j  = 0; j < n; j++)
            {
                bool border = false;
                // mark all xs as 1
                if(board[i][j] == 'X') 
                {
                    vis[i][j] = 1;
                }
                // run dfs from all boundary Os (add vis there itself)
                else if(i == 0 || i == m-1 || j == 0 || j == n-1) 
                {
                    border = true;
                }
                if(board[i][j] == 'O' && border == true && !vis[i][j]) dfs(board, vis, i, j);
            }
        }

        // if O and not vis, change to X
        for(int i = 0; i < m; i++)
        {
            for(int j  = 0; j < n; j++)
            {
                if(board[i][j] == 'O' && !vis[i][j]) board[i][j] = 'X';
            }

        }
    }
};
