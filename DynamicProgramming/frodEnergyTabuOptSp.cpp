#include<algorithm>
#include<cmath>

class Solution {
  public:
    int minCost(vector<int>& height) 
    {
        vector<int> dp(height.size()+1,-1);
        int old2 = 0;
        //this is the one which has ans to 
        int old1 = 0;
        if(height.size() == 0) return 0;
        int first, second, curr;
        for(int i = 1; i<height.size(); i++)
        {
            first = old1 + abs(height[i] - height[i-1]);
            if(i>1) second = old2 + abs(height[i] - height[i-2]);
            else second = 2*first;
            curr = min(first, second);
            old2 = old1;
            old1 = curr;
        }
        return curr;
    }
};
