class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        //BF solution is to make a count array to store the number of times a number comes n the list. This method is called Hashing. we will make a new array of size 10 and update the count of each element. when the count becomes 2, we output that one as the element that is repeated.
        //or BF soln can be to sort the array and then check
        //since this is constant extra space, maybe we can use 2 ptrs and check them like youd do in bubble sort. So i will write that code rn 
        int answer = 0;       
        for(int start = 0; start < nums.size(); start++)
        {
            for (int current = start + 1; current < nums.size(); current++)
            {
                if(nums[start] == nums[current])
                {
                    answer = nums[current];   
                    break;
                }
            }
        }
        return answer;
    }
};
//time complexity is O(n^2). time limit ws exceeded
