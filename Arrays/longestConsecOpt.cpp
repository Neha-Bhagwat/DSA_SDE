class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //optimal approach.. put everything in a hashset. 
        unordered_set<int> st;
        int longest = 0;
        int n =  nums.size();
        if(nums.size() == 0) return 0;
        for(int i = 0; i < n; i++)
        {
            st.insert(nums[i]);
        }
        for(auto it : st)
        {
            if( st.find(it-1) == st.end()) //if the previous number is not present in the set
            {
                int cnt = 1;
                int x = it;
                //if not present, find the next number until you get it. (use iterator)
                while(st.find(x+1) != st.end())
                {
                    cnt++;
                    x = x+1;
                }
                longest = max(longest, cnt);
            }
        }
        return longest;
    }
};

//tc is O(3n), and sc is O(n)
