class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int start = 0, profit = 0, maxi = 0;
        for(int i=0; i < prices.size()-1; i++)
        {
            // if arr[i] < arr[i+1] and the other prices[start] is greater than this new one, then store that index
            if(prices[i] > prices[i+1] && prices[start] > prices[i+1])
            {
                //use start index to calculate the subtraction between indices
                start = i+1;
            }
            //calculate the max profit
            profit = prices[i+1] - prices[start];
            maxi = max(profit,maxi);
        }
        return maxi;
    }
};
