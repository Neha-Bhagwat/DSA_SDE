class Solution {
public:
    int uniquePaths(int m, int n) 
    {
        //here, we use the logic of finding paths using nCr. n being the total number of possible paths and r being n-1, where n is the number of columns, so the total number of choices we could take
        int total_paths = m+n-2;
        int r = n-1;
        double answer = 1;

        //now to find nCr
        for(int i = 1; i <= n-1 ; i++)
        {
            answer = answer*(total_paths-r+i)/i;
        }
        return (int)answer;
    }
};
