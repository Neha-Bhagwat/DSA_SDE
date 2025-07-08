class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> ds; 
        findSubsets(nums, 0, ds, ans);
        return ans;
    }

    void findSubsets(vector<int>& nums, int idx, vector<int>& ds, vector<vector<int>>& ans)
    {
        ans.push_back(ds);
        for(int i = idx; i<nums.size(); i++)
        {
            if(i!=idx && nums[i] == nums[i-1]) continue; //this is to explore the case when there might be a samw element that we want to avoid.
            ds.push_back(nums[i]); //we push the unique values into nums
            findSubsets(nums, i+1, ds, ans); //recursive call to explore subsets with greater length and using the next index
            ds.pop_back(); //done for backtracking. this is so that we avoid having multiple subsets at a time in ds. so when we push the new element, we can pop the old ones back
        }
    }
};

//tc->O(2^n*k) --here, k is the average length of the subset. we do ans.push_back(ds). this accounts for that change
//sc->O(2^n)*O(k) --again, average length is k here for each subset. there are 2^n subsets
//depth of recursion is O(n). or Auxiliary Space Complex.
