//brute force algorithm. TC->O(n^2), SC->O(1)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> op;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[j]+nums[i]==target){
                    // op.push_back(i);
                    // op.push_back(j);
                    // return op;
                    // instead of this, you can just write
                    return{i,j};
                }
            }
        }
        //return op;
        //else say
        return {};
    }
};
