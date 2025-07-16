class Solution {
  public:
    // calculate the maximum sum with out adjacent
    // doing this using tabulation
    int findMaxSum(vector<int>& arr) 
    {
        vector<int> dp(arr.size(), -1);
        // dp[0] = arr[0];
        int minus2 = arr[0];
        // d[1] = max(arr[0], arr[1]);
        int minus1 = max(arr[0], arr[1]);
        int nottake, curr;
        int take;
        for(int i=2; i<arr.size(); i++)
        {
            // first option is that, you take this one and the 2nd previous
            take = arr[i]+minus2;
            // other option is that, you dont take this one
            nottake = minus1;
            curr = max(take, nottake);
            minus2 = minus1;
            minus1 = curr;
        }
        return minus1;
    }
};
