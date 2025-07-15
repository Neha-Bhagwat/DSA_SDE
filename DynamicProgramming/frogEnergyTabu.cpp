#include<algorithm>
#include<cmath>

class Solution {
  public:
    int minCost(vector<int>& height) 
    {
        vector<int> dp(height.size()+1,-1);
        dp[0] = 0;
        int first, second;
        for(int i = 1; i<height.size(); i++)
        {
            first = dp[i-1] + abs(height[i] - height[i-1]);
            if(i>1) second = dp[i-2] + abs(height[i] - height[i-2]);
            else second = 2*first;
            dp[i] = min(first, second);
        }
        return dp[height.size()-1];
    }
};
