class Solution {
public:
    int fib(int n) 
    {
        int prev2 = 0, prev1 = 1, curr = 0; // we only need to store 
        for(int i = 2; i<=n; i++) //here, i should go to n, not only till n-1. this is because you need to do this operation n-1 times exactly. (2 going to n makes it n-1 operations)
        {
            curr = prev1 + prev2;
            prev2 = prev1;
            prev1 = curr;
        }
        return curr;
    }
};
