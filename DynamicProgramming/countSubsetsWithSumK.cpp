// Count subsets with sum K
// Given an array arr of n integers and an integer K, count the number of subsets of the given array that have a sum equal to K. Return the result modulo (109 + 7).

// Example 1
// Input: arr = [2, 3, 5, 16, 8, 10], K = 10
// Output: 3
// Explanation: The subsets are [2, 8], [10], and [2, 3, 5].

// Example 2
// Input: arr = [1, 2, 3, 4, 5], K = 5
// Output: 3

class Solution{
	public:
    // int recur(vector<int>& arr, int idx, int target)
    // {
    //     if(target == 0) return 1;
    //     if(idx == 0) return arr[0] == target;
    //     int not_take = recur(arr, idx-1, target);
    //     int take = 0;
    //     if(target >= arr[idx]) take = recur(arr, idx-1, target-arr[idx]);
    //     return take+not_take;
    // }
	int perfectSum(vector<int>&arr, int K){
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(K+1,0));
        for(int idx = 0; idx < n; idx++)
        {
            dp[idx][0] = 1; 
        }
        dp[0][arr[0]] = 1;

        for(int idx = 1; idx < n; idx++)
        {
            for(int target = 1; target <= K; target++)
            {
                int not_take = dp[idx-1][target];
                int take = 0;
                if(target >= arr[idx]) take = dp[idx-1][target-arr[idx]];
                dp[idx][target] = take + not_take;
            }
        }
        return dp[n-1][K];
        // return recur(arr, n-1, K);
	}
};
