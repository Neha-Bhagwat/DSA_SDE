class Solution {
public:
    bool check(int row, int column, vector<vector<char>>& board, char number)
    {
        int duprow = row;
        int dupcolumn = column;
        //checking for vertical, change rows
        for(int i = 0; i < 9; i++)
        {
            if(board[i][column] == number)
            {
                return false;
            }
        
        //checking horizontally
        
            if(board[row][i] == number)
            {
                return false;
            }
        
        //check for box
            if(board[(row/3)*3+i/3][(column/3)*3+i%3] == number)
            {
                return false;
            }
        }
        return true;
    }


    bool recurSudoku(vector<vector<char>>& board)
    {
        //base case
        
        //find first blank space
        for(int i = 0; i< 9; i++)
        {
            for(int j = 0; j<9; j++)
            {
                if(board[i][j] == '.')
                {
                    //then loop from 1 to 9
                    for(char c = '1'; c <= '9'; c++)
                    {
                        //see if it is possible to put that number there
                        if(check(i, j, board, c))
                        {
                            //then put no there
                            board[i][j] = c;
                            //then recur
                            if(recurSudoku(board)) return true;
                            //now, backtrack
                            else board[i][j] = '.';
                        }
                    }
                    //if this doesnt work from 1 to 9, we return false for this one
                    return false; //then it will backtrack
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        recurSudoku(board);
    }
};
