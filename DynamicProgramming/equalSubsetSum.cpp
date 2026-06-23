// Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.
// Example 1:
// Input: nums = [1,5,11,5]
// Output: true
// Explanation: The array can be partitioned as [1, 5, 5] and [11].

// Example 2:
// Input: nums = [1,2,3,5]
// Output: false
// Explanation: The array cannot be partitioned into equal sum subsets.

// Constraints:
// 1 <= nums.length <= 200
// 1 <= nums[i] <= 100

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = 0, n = nums.size();
        bool taken, not_taken;
        target = accumulate(nums.begin(), nums.end(), 0);
        if(target % 2 == 1) return false;
        target /= 2;
        // vector<vector<int>> dp(n, vector<int>(target+1, 0));
        vector<int> dp(target+1, 0);
        vector<int> prev(target+1, 0);
        // for(int x = 0; x < n; x++) dp[x][0] = 1;
        prev[0] = 1;
        // for the case of 1 input or if [9,5] is the testcase
        if(nums[0]>target) return false;
        // dp[0][nums[0]] = 1;
        prev[nums[0]] = 1;
        for(int x = 1; x < n; x++)
        {
            for (int t = 1; t <= target; t++)
            {
                if(t < nums[x]) taken = false;
                // else taken = dp[x-1][t-nums[x]];
                else taken = prev[t-nums[x]];
                // not_taken = dp[x-1][t];
                not_taken = prev[t];
                // dp[x][t] = taken | not_taken;
                dp[t] = taken | not_taken;
            }
            prev = dp;
        }
        return prev[target];
    }
};
