// Given an array arr containing positive integers. Find the maximum sum of any possible subsequence such that no two numbers in the subsequence should be adjacent in array arr.
class Solution {
  public:
    int maxRecur(int idx, vector<int>& arr, vector<int>& dp)
    {
        int pick, not_pick;
        //base case
        if(idx == 0) return dp[idx] = arr[idx];
        //edge case
        if(idx < 0) return 0;
        
        if(dp[idx]!=-1) return dp[idx];
        pick = arr[idx]+maxRecur(idx-2, arr, dp);
        not_pick = maxRecur(idx-1, arr, dp);
        return dp[idx] = max(pick, not_pick);
    }
    // calculate the maximum sum with out adjacent
    int findMaxSum(vector<int>& arr) 
    {
        vector<int> dp(arr.size(), -1);
        return maxRecur(arr.size()-1, arr, dp);
    }
};
