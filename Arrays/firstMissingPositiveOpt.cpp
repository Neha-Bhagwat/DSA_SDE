class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // check if 1 is present or not
        bool one = false;
        int n = nums.size();
        for(int i= 0; i < n; i++)
        {
            if(nums[i] == 1) one = true;
            else
            {
                if(nums[i] <= 0 || nums[i] > n)
                {
                    nums[i] = 1;
                }
            }
        }

        if(!one) return 1;

        // flip the indices of present numbers to -ve
        for(int i = 0; i < n; i++)
        {
            int ans = abs(nums[i]);
            int idx = ans-1;
            if(nums[idx] > 0) nums[idx] *= -1;
        }

        // look for 
        for(int i = 0; i < n; i++)
        {
            if(nums[i] > 0) return i+1;
        }

        // if there are no -ve nos in the array
        return n+1;
    }
};
