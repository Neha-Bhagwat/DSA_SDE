


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        // easiest way I can think of :
        sort(nums.begin(), nums.end());
        int comp = 0; //have a number that is used to compare to the next positive ele
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] <= 0)continue; //no need to see, move on.
            else
            {
                if(nums[i] == comp) continue; //in case there are duplicates, we do not inc comp
                else if(nums[i] == comp+1) comp++; //if nums[i] has moved on to the next positive num, inc comp as well
                else return ++comp; //if there is one number missed, return it
            }
        }
        return ++comp; //if till the end you dont find anything, then the culprit is the 1st positive num after comp. so return that
    }
};
