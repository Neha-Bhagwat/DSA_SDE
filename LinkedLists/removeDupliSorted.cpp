class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //brute force. after deletion shift all elements to the front to replace that one.
        int n = nums.size();
        int count = n;
        for(int i = 1 ; i < n; i++)
        {
            if(nums[i] == nums[i-1])
            {
                count--;
                for(int j = i; j<n-1;j++)
                {
                    nums[j] = nums[j+1];
                }
                i--;
            }
        }
        //TC->O(n x duplicates) .. time limit exceeded
        //SC->O(1)
        //second bf. new array with all the sorted elements
        return count;
    }
};
