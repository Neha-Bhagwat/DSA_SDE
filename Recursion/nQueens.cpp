class Solution {
public:
    bool isSafe(int n, int row, int column, vector<string> &board)
    {
        //in the board if there is a queen at left, top or diagonally either ways back then not safe
        //for horizontally behind
        int duprow = row;
        int dupcolumn = column;
        for(int i = column; i>=0; i--)
        {
            if(board[row][i] == 'Q') return false;
        }
        //for diagonally back top
        column = dupcolumn;
        row = duprow;
        while(row >= 0 && column >= 0)
        {
            if(board[row][column] == 'Q') return false;
            row--;
            column--;
        }

        //for diagonally back down
        column = dupcolumn;
        row = duprow;
        while(row >= 0 && column >= 0 && row<n)
        {
            if(board[row][column] == 'Q') return false;
            row++;
            column--;
        }
        return true;
    }

    void solve(int n, int column, vector<string> &board, vector<vector<string>> &ans)
    {
        //base case
        if(column == n)
        {
            ans.push_back(board);
            return;
        }
        //check if its safe to put a queen someplace next column
        for(int row=0; row<n; row++)
        {
            if(isSafe(n, row, column, board))
            {
                //put a queen
                board[row][column] = 'Q';
                //if it is safe to, go recur
                solve(n, column+1, board, ans);
                //backtrack
                board[row][column] = '.';
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) 
    {
        //initialize everything including board and all
        vector<string> board(n);
        vector<vector<string>> ans;
        string s(n, '.');
        for(int i = 0; i < n; i++)
        {
            board[i] = s;
        }
        solve(n, 0, board, ans);
        return ans;
    }
};
