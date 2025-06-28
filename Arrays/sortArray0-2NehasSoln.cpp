//brute force here would be to sort in place using any of the known sorting algorithms

class Solution {
public:
    void sortColors(vector<int>& nums) {
        //my logic.. go around the array. count number of 0s 1s and 2s.
        int len = nums.size(), cnt0=0, cnt1=0, cnt2=0;
        for(int i = 0; i < len; i++)
        {
            if(nums[i] == 0)
            {
                cnt0++;
            }
            else if(nums[i] == 1)
            {
                cnt1++;
            }
            else if(nums[i] == 2)
            {
                cnt2++;
            }
        }
      //after that, work the array accordingly
        for(int i = 0; i < len; i++)
        {
            if(cnt0!=0)
            {
                nums[i]=0;
                cnt0--;
            }
            else if(cnt1!=0)
            {
                nums[i]=1;
                cnt1--;
            }
            else if(cnt2!=0)
            {
                nums[i]=2;
                cnt2--;
            }
        }
    }
};
