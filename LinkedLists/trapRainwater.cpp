class Solution {
public:
    int trap(vector<int>& height) {
        //the amount of rain stored between buildings is the difference between the minimum of left max height and right max height and the value of the block itself
        //we need to get minimum between left max and right max
        //we need left and right pointers to do this job for us
        int n = height.size();
        int left = 0, right = n-1, leftmax = 0, rightmax = 0;
        int quantity = 0;
        while(left<=right) 
        {
            if(height[left] <= height[right])
            {
                //this is the condition of the minimum of left and right is left 
                if(height[left] >= leftmax) leftmax = height[left]; //here no water is stored but the max wall length of left is updated
                else
                {
                    //in this case, there is a bigger wall to the left so water is stored
                    quantity += (leftmax-height[left]);
                }
                left++;
            }
            //this is the case where right wall is the minimum one
            else
            {
                if(height[right] >= rightmax) rightmax = height[right]; //here water is stored and the right wall is smaller than the left one
                else quantity += (rightmax-height[right]);
                right--;
            }
        }
        //when the two pointers cross, we can return the answer
        return quantity;
    }
};
//TC->O(N)
//SC->O(1)
