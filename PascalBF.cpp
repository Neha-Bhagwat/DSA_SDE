class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;
        pascal.resize(numRows);
        for(int i = 0; i < numRows; i++)
        {
            pascal[i]. resize(i+1);;
        }
       // pascal.size() = numRows;
        //pascal[numRows-1].size()=numRows;
        pascal[0] = {1};
        for(int i = 1; i < numRows; i++)
        {
            pascal[i][0] = 1;
            pascal[i][i] = 1;
            for(int j = 1; j < i; j++)
            {
                pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j];
            }
        }
        return pascal;
    }
};

//time complexity--> n+n^2
//space complexity--> matrix, so n^2
