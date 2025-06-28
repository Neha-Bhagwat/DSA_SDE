class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //bf approach is iterating through every single element by using those 3 for loops.
        int n = nums.size();
        // to store unique, we need to use a set
        set<vector<int>> st;
        for(int i=0; i<n; i++){
            for(int j=i+1;j<n;j++)
            {
                for(int k = j+1; k<n; k++)
                {
                    if(nums[i]+nums[j]+nums[k] == 0)
                    {
                        vector<int>temp = {nums[i], nums[j], nums[k]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
        return vector<vector<int>>(st.begin(),st.end());
    }
};
