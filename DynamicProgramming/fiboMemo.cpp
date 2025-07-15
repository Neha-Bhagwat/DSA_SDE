class Solution {
public:
    int recurFib(int n, vector<int> &dp)
    {
        // when you see that your recursion code is working, then add the dp element
        //base case
        if(n <= 1) return n;
        //if dp[n] is not -1, there is a value stored there already. we can return this directly
        if(dp[n] != -1) return dp[n]; 
        //if there is a new value to be computed, you do this to get it
        return dp[n] = recurFib(n-1, dp)+ recurFib(n-2, dp);
    }
    int fib(int n) 
    {
        vector<int> dp(n+1, -1); //initialize all the elements to -1 to keep a track of them. we need n+1 number of elements in the vector.
        return recurFib(n, dp);
    }
};
