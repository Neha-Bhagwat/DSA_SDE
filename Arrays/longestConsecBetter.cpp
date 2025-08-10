// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
// You must write an algorithm that runs in O(n) time.


// Example 1:

// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
// Example 2:

// Input: nums = [0,3,7,2,5,8,4,6,0,1]
// Output: 9
// Example 3:

// Input: nums = [1,0,1,2]
// Output: 3

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

//tc is O(nlogn), and sc is O(1)
// one more problem is that this causes the array to change
