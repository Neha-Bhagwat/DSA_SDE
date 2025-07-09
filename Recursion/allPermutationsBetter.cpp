//check the logic in strivers sheet
//SC->O(N)
//TC->O(N!*N)

class Solution {
public:
    void recurPermute(vector<int>& nums, vector<int> &ds, vector<vector<int>>& ans, int freq[])
    {
        if(ds.size() == nums.size())
        {
            ans.push_back(ds);
            return;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            //if its there in the map, then ignore, otherwise add
            if(freq[i] == 0)
            {
                //mark the element
                freq[i] = 1;
                //then, recur
                ds.push_back(nums[i]);
                recurPermute(nums, ds, ans, freq);
                //backtrack
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        vector<int> ds;
        int freq[nums.size()];
        for(int i=0; i<nums.size(); i++)  freq[i] = 0;
        recurPermute(nums, ds, ans, freq);
        return ans;
    }
};
