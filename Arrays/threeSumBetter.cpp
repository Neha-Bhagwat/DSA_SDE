class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //better approach is hashing. here, we will be able to optimize it to O(n2)
        set<vector<int>> st;
        int third = 0;
        int n = nums.size();
        //now 2 loops will iterate i and j
        for(int i =0; i <n; i++)
        {
            //hashset needs to be emptied
            set<int> hashset;
            for(int j = i+1; j < n; j++)
            {
                third = -(nums[i]+ nums[j]);
                //now check for third in hashset
                if(hashset.find(third) != hashset.end())
                {
                    vector<int> temp ={nums[i], nums[j], third};
                    //we need to sort this so that same things do not get repeaated
                    sort(temp.begin(), temp.end());
                    st.insert(temp); //remember this
                }
                hashset.insert(nums[j]);
            }
        }
        //this approach gives TC->O(n2+logm) where log m is variable part in between i and j
        //space complexity is O(n)+O(no of triplets)*2
        return vector<vector<int>>(st.begin(), st.end());
    }
};
