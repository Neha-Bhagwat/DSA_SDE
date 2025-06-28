class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //initializing n, m and vectors for rows and column numbers used to mark
       int n = matrix.size(); 
       int m = matrix[0].size();
        // -> ith row matrix[i][0]
        // -> jth column matrix[0][j]
        int col0 = 1;
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0; j < m; j++)
            {
                //if there is an element which is zero, mark the row and column
                if(matrix[i][j] == 0)
                {
                    // rowarr[i] = 1;
                    // columnarr[j] = 1;
                    if(j!=0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                    }
                    else{
                        matrix[i][0] = 0;
                        col0 = 0;
                    }
                }
            }
        }
        //then mark the rows and columns as 0 as long as they are not a part of the index 0 at row or column
        for(int i = 1 ; i < n ; i++)
        { 
            for(int j = 1 ; j < m; j++)
            {
                if(matrix[i][j] != 0) {
                //check for the column or row to be 0
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    //if either of them is 0, mark the element as 0.
                    matrix[i][j] = 0;
                }
            }
            }
        }

        //now to mark the column based on the rows
        //if the 0th row is 0, all the columns are 0
         if(matrix[0][0] == 0)
        {
            for(int i = 0; i < m ; i++)
            {
                matrix[0][i] = 0;
            }
        }

        if(col0 == 0)
        {
            for(int i = 0; i < n ; i++)
            {
                matrix[i][0] = 0;
            }
        }
    }
};
