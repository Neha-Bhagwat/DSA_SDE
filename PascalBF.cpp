class Solution {
public:
    vector<vector<long long int>> generate(int numRows) {
        vector<vector<long long int>> pascal;
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

//make it long long int to prevent overflow
//time complexity--> n+n^2
//space complexity--> matrix, so n^2
//to find one single element, we use nCr formula. We run for loop r times as product *= n-i/r-i from i = 1 until i != r. here time is O(r) and space complexity is O(1). 
