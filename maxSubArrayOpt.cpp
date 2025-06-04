class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long sum = 0, maxi=nums[0], len = nums.size();
        for(int i = 0; i< len; i++)
        {
        sum += nums[i]; //initially the sum is initialized to the first element
        
        //now we check if max is 
        maxi = max(sum, maxi);

        //if else condition to check if max>sum. when max<sum then update the end pointer to i. in for loop remember to not include the last end element then.

        if(sum<0)
        {
            sum = 0;
            //here define a start variable that stores i. we need this if we want to remember the starting of that subarray.
        }
        
        }
        return maxi;
    }
};
