class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int mini = prices[0], profit = 0, maxi = 0;
        for(int i=0; i < prices.size(); i++)
        {                        
            //calculate the max profit
            profit = prices[i] - mini;
            //calculating the maximum profit possible
            maxi = max(profit, maxi);
            // for each iteration, calculate the minimum element on the left of ith element in prices array
            mini = min(prices[i], mini);
        }
        return maxi;
    }
};
