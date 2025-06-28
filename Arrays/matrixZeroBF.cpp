//Q.Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's. Do it in place. Here i use extra memory to store or flag the columns and rows that need to be replaced with 0.

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //initializing n, m and vectors for rows and column numbers used to mark
       int n = matrix.size();
       int m = matrix[0].size();
        vector<int> rowarr(n,0);
        vector<int> columnarr(m,0);
      //iterating through the matrix to find 0s
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = 0; j < m; j++)
            {
                //if there is an element which is zero, mark the row and column
                if(matrix[i][j] == 0)
                {
                    rowarr[i] = 1;
                    columnarr[j] = 1;
                }
            }
        }
      
        //then make the rows as 0 as needed
        for(int i = 0 ; i < n ; i++)
        {
            if(rowarr[i] == 1)
            {
              //make everything in that row 0
                for(int j = 0; j < m; j++)
                {
                    matrix[i][j] = 0;
                }   
            }
        }

        //then make the columns as 0 as needed
        for(int j = 0 ; j < m ; j++)
        {
            if(columnarr[j] == 1)
            {
              //make everything in that column 0
                for(int i = 0; i < n; i++)
                {
                    matrix[i][j] = 0;
                }   
            }
        }
    }
};
