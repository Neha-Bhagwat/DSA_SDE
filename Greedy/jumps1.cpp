// You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

// Return true if you can reach the last index, or false otherwise.

// Example 1:
// Input: nums = [2,3,1,1,4]
// Output: true
// Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

// Example 2:
// Input: nums = [3,2,1,0,4]
// Output: false
// Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.

// Constraints:
// 1 <= nums.length <= 104
// 0 <= nums[i] <= 105

//Intuition:
//Keep a maxLength stored which is the maximum index you can reach if you jump from one place
//while iterating over the array, you return when maxLen goes to the last index or beyond
//return false if you get stuck at one index i.e. when maxLen<idx. idx is the idx you are at while linearly iterating.

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxLen = 0;
        int i = 0;   
           while(maxLen >= i)
           {
                if(maxLen>=nums.size()-1) return true;
                maxLen = max(maxLen, i+nums[i]);
                // cout<<i<<" "<<maxLen<<endl;
                i++;
           } 
           return false;
    }
};
