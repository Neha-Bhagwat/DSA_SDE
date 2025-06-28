class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //this is the optimal solution
        //use the sort operator
        sort(intervals.begin() , intervals.end()); // time complexity is O(nlogn)

        //then club intervals. We do ths by making a new answer array. initializing indexing for new vector
        vector<vector<int>> ans;
        int j = 0;

        //first, add the first element of ans
        ans.push_back(intervals[0]);

        for(int i = 1; i < intervals.size(); i++)
        {
            if(intervals[i][0] > ans.back()[1]) 
            {
                //if a new interval is found, push it back
                ans.push_back(intervals[i]);
                j++;
            }
            else
            {
                //check if the original interval needs to be increased
                ans[j][1] = max(ans[j][1], intervals[i][1]);
            }
        }
        
        return ans;
    }
};
