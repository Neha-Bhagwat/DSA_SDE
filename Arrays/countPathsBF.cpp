class Solution {
public:
//brute force algorithm, we use recursion and make a recursive tree.
//TC->O(2^n) SC->O(2^n) stack
    int countPaths(int m, int n, int i, int j)
    {
        //base case1
        if(i == m-1 && j == n-1)
        {
            return 1;
        }
        else if(i >= m || j >=n)
        {
            return 0;
        }
        //recursion
        else
        {
            return countPaths(m,n,i+1,j) + countPaths(m,n,i,j+1);
        }
    }

    int uniquePaths(int m, int n) 
    {
        return countPaths(m, n, 0, 0);
    }
};
