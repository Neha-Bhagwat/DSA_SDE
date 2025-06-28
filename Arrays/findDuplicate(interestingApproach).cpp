// #import <mathio>
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // we need to find the repeating numbers 
        // we will travel the vector line wise and make the values at the indexes negative if they are positive. if on encountering a number we find it is negative means that this number is again found thus this is a repeated number
        // if indeed this happens, it means that, that particular number has been visited b4
        // thus, we return the value as the answer        
        int repNum = 0 ;
        for(int i = 0 ; i < nums.size() ; i++){
            int val = abs(nums[i]);
            if(nums[val]>0)nums[val]=-1*(nums[val]);
            else{
                return abs(nums[i]);
            }
        }return 0 ;
    }
};
