class Solution {
public:
//kinda straightforward
    int findMaxConsecutiveOnes(vector<int>& nums) 
    {
        int n = nums.size(), count = 0, maxcount=0;;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] != 1)
            {
                maxcount=max(count,maxcount);
                count = 0;
            }
            else
            {
                count++;
                maxcount=max(count,maxcount);
            }
        }
        return maxcount;    
    }
};
