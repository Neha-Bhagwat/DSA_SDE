class Solution {
public:
    void sortColors(vector<int>& nums) {
        //dutch national flag algorithm. Here 0s will be between start and low-1. 1s will be between low and mid-1. Between mid and high-1 will be the unsorted array and between high and end will be 2s.
        int len = nums.size();
        //we need 3 pointers, low, mid and high, which will have the given indexes. low and mid initialized to start of array as between mid and high, the unsorted array will remain.
        int low=0, mid=0, high=len-1;
        while(mid<=high)
        {
            //here, if nums[mid] has a 0, then we will swap it with the 1 present at low (if there is a 1 present there). then increment low and mid
            if(nums[mid] == 0)
            {
                swap(nums[mid], nums[low]);
                mid++;
                low++;
            }
            //if there is a 1 at nums[mid], just inc mid to add that to the 1s ka section
            else if(nums[mid] == 1)
            {
                mid++;
            }
            //if there is a 2 at nums[mid], swap it with the nums[high] to get a 2 at the end. dont inc mid. just dec high
            else
            {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
        
    }
};
