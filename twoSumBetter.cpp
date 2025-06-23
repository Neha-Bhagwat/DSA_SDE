//this solution uses hashmaps. if no number matches target-num inside the hashmap, you add number to the hashmap
//TC-> O(n*logn) for ordered map. if you use unordered, TC->O(n) to O(n^2)
//SC-> O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> mpp;
        int n = nums.size();
        for (int i =0; i < n; i++)    
        {
            //int a = nums[i];
            int more = target - nums[i];
            //check if more is in the map
            if(mpp.find(more) != mpp.end()) //if you dont find it itll go to the end
            {
                //mpp[more] gives the index
                return {mpp[more],i};
            }
            mpp[nums[i]] = i;
        }
        return {};
    }
};
