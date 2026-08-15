// Partition a set into two subsets with minimum absolute sum difference
// Given an array arr of n integers, partition the array into two subsets such that the absolute difference between their sums is minimized.

// Example 1
// Input: arr = [1, 7, 14, 5]
// Output: 1
// Explanation: The array can be partitioned as [1, 7, 5] and [14], with an absolute difference of 1.

// Example 2
// Input: arr = [3, 1, 6, 2, 2]
// Output: 0
// Explanation: The array can be partitioned as [3, 2, 2] and [6, 1], with an absolute difference of 0.

class Solution{

  public:
	int minDifference(vector<int>&arr, int n)  { 
        int sum = 0;
        sum = accumulate(arr.begin(), arr.end(), 0);
        vector<vector<int>> dp(n, vector<int>(sum+1, 0));

        for(int row = 0; row < n; row++)
        {
            dp[row][0] = 1;
        }

        dp[0][arr[0]] = 1;

        for(int idx = 1; idx < n; idx++)
        {
            for(int target = 1; target <= sum ; target++)
            {
                bool not_take = dp[idx-1][target];
                bool take = false;
                if(target >= arr[idx]) take = dp[idx-1][target-arr[idx]];
                dp[idx][target] = take | not_take;
            }
        }

        // bottom row => whether sum is possible for a subset
        int diff = 0, minDiff = INT_MAX;
        for(int target = 0; target <= sum/2; target++)
        {
            if(dp[n-1][target] == true)
            {
                diff = abs(sum - 2*target);
                minDiff = min(diff, minDiff);
            }
        }
        return minDiff;
	} 
};
