class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //ordered hashset ig.. i just dont know how
        //bf method: sort it and then check for consecutive usign a counter and longest
        //better method can have a hashset, but time complexity and space increases
        //in the case that we dont want a hashset, first sort the array then use the foll logic,
        //first of all, before we sort, taking care of the condition where nums is empty
        if(nums.size() == 0)
        {
            //if nums is empty, then return 0
            return 0;
        }
        sort(nums.begin(), nums.end());
        int cnt = 1;
        int longest = 1;
        int n = nums.size();
        //when you go to the first number, update the lastSmallest to that.
        int lastSmallest = nums[0];
        for(int i = 0; i <n; i++)
        {
            //if the nums[i] - 1 == lastSmallest, then the sequence is getting continued. so then add i to counter (initialy 1), then go ahead and make lastSmallest as nums[i]
            if(nums[i]-1 == lastSmallest)
            {
                cnt++;
                lastSmallest = nums[i];
            }
            else if(nums[i] != lastSmallest)
            {
                //else if they arent equal, reset counter and then make lastSmallest equal to nums[i]
                cnt = 1;
                lastSmallest = nums[i];
            }
            //longest is max between longest and cnt
            longest = max(longest, cnt);
        }
        return longest;
    }
};

//tc is O(n2), and sc is O(1)
