#include<algorithm>
#include<cmath>

class Solution {
  public:
    int minCostRecursion(int idx ,vector<int>& height, vector<int> &dp)
    {
        int left, right;
        //base case
        if(idx==0) return 0;
        //recursive calls
        if(dp[idx] != -1) return dp[idx];
        else 
        {
            left = minCostRecursion(idx-1, height, dp)+abs(height[idx]- height[idx-1]);
            if(idx != 1)  right = minCostRecursion(idx-2, height, dp)+abs(height[idx]-height[idx-2]);
            else right = left*2;
            //final return
            return dp[idx] = min(left, right);
        }
    }
    int minCost(vector<int>& height) {
        vector<int> dp(height.size()+1,-1);
        return minCostRecursion(height.size()-1, height, dp);
    }
};

//all the necessary explaination is present in my ipad notes
