//DO NOT FORGET TO PASS STUFF BY REFERENCE
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        //you can either put all the combinations in a set
        //or you can did what we did before, and sort everything
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        findCombinations(0, candidates, target, ans, ds);
        //after that, we can make a recursion tree to either take an element or not take it.
        return ans;
    }

    void findCombinations(int idx, vector<int>& candidates, int target, vector<vector<int>> &ans, vector<int> &ds)
    {   
        //the base case is when the index goes to the end of the candidates array.
        //when the target is zero at this point, it means that you have found the appropriate solution!
        if(target == 0)
        {
            ans.push_back(ds);
            return;  
        }
        //now the next case is when we go on ahead to the next series
        for(int i = idx; i < candidates.size(); i++)
        {
            //you should be able to take only if previous element was selected or no duplicate
            if(candidates[i] > target) break;
            if(idx < i && candidates[i] == candidates[i-1]) continue;
            ds.push_back(candidates[i]);
            findCombinations(i+1, candidates, target-candidates[i], ans, ds);
            ds.pop_back();
        }
    }
};
