class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //this uses an algorithm called tortoise and hare algo. here, we make a sort of loop. Since each integer is in the range of 1,n, we can safely write fast = nums[nums[fast]]. this will give us a loop which will close at some point. 
        // after we get that loop, we need to find the intersection point. we use this method for that
        int slow = nums[0];
        int fast = nums[0];
        //either add these 2 lines, or add a do-while loop as the first loop.
        slow = nums[slow];
        fast = nums[nums[fast]];
        //fast ptr will go ahead by 2 steps while the slow one will go ahead in the loop by only one step
        while(slow!=fast)
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } 
        //after the intersection point arrives, we set the value of the fast pointer as nums[0]. 
        fast = nums[0];
        while(slow!=fast)
        {
            //now each will move with the speed of 1 link
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};
