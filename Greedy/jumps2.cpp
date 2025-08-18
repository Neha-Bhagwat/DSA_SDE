// You are given a 0-indexed array of integers nums of length n. You are initially positioned at index 0.

// Each element nums[i] represents the maximum length of a forward jump from index i. In other words, if you are at index i, you can jump to any index (i + j) where:

// 0 <= j <= nums[i] and
// i + j < n
// Return the minimum number of jumps to reach index n - 1. The test cases are generated such that you can reach index n - 1.

// Example 1:
// Input: nums = [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.

// Example 2:
// Input: nums = [2,3,0,1,4]
// Output: 2

//idea - since we think of recursion in this case, we will keep a range, one that goes from the first place where you need to jump atleast n times and till the last place.

class Solution {
public:
    int jump(vector<int>& nums) {
        int left = 0, right = 0, jumps = 0;
        while(right<nums.size()-1)
        {
            int farthest = 0;
            for(int idx = left; idx<=right; idx++)
            {
                farthest = max(idx+nums[idx], farthest);
            }
            left = right+1;
            right = farthest;
            jumps++;
            // cout<<left<<" "<<right<<" "<<jumps<<endl;
        }    
        return jumps;
    }
};
