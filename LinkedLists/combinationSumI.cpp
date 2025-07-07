//here, we need to see if any subsequence of array candidates sums up to target value. if there are multiple ones return all of them

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        findCombinations(candidates, target, 0, ds, ans);
        return ans;
    }

    void findCombinations(vector<int>& candidates, int target, int idx, vector<int> &ds, vector<vector<int>> &ans)
    {
        //base case where 
        if(idx == candidates.size())
        {
            if(target == 0)
            {
                ans.push_back(ds);
            }
            return;
        }
        //inserting element if target>element
        if(candidates[idx]<=target)
        {
            //case where we take the element
            ds.push_back(candidates[idx]);
            findCombinations(candidates, target-candidates[idx], idx, ds, ans);
            ds.pop_back();
        }
        //case where we dont take the element (can be either if the first condition isnt met or in general also)
        findCombinations(candidates, target, idx+1, ds, ans);   
    }
};
