class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //one way you can do this is by doing hashing. if the value at temp array ever exceeds n/2, then we return element
        int n = nums.size();
        int maximum = *max_element(nums.begin(), nums.end());
        vector<int> temp(maximum+1,0);
        for(int i = 0; i < n; i++)
        {
            temp[nums[i]]++; 
            if(temp[nums[i]] > n/2)
            {
                return nums[i];
            }
        }
        return -1;
    }
};

//this solution did not work, as negative numbers are possible in the array but impossible in the index
