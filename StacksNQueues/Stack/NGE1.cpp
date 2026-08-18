// 496. Next Greater Element I

// The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

// You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

// For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

// Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.

// Example 1:
// Input: nums1 = [4,1,2], nums2 = [1,3,4,2]
// Output: [-1,3,-1]
// Explanation: The next greater element for each value of nums1 is as follows:
// - 4 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.
// - 1 is underlined in nums2 = [1,3,4,2]. The next greater element is 3.
// - 2 is underlined in nums2 = [1,3,4,2]. There is no next greater element, so the answer is -1.

// Example 2:
// Input: nums1 = [2,4], nums2 = [1,2,3,4]
// Output: [3,-1]
// Explanation: The next greater element for each value of nums1 is as follows:
// - 2 is underlined in nums2 = [1,2,3,4]. The next greater element is 3.
// - 4 is underlined in nums2 = [1,2,3,4]. There is no next greater element, so the answer is -1.

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        //instead of traversing normally, we will go right to left
        int n = nums2.size();
        stack<int> st;
        unordered_map<int,int> mp;
        int ans;
        for(int i = n-1; i >= 0; i--)
        {
            // if stack is empty, ans will be -1
            // cout<<"idx :"<<i<<endl;
            if(st.empty() == true) 
            {
                ans = -1;
            }
            // if it is not empty, we will pop the elements that are lesser than ours
            else
            {
                while(!st.empty() && st.top() <= nums2[i])
                {
                    st.pop();
                }
                // the next number will be the nge
                if(!st.empty())ans = st.top();
                // for the case that num is the largest in right part of arr
                else ans = -1;
            }
            st.push(nums2[i]);
            mp.insert({nums2[i], ans});
            // cout<<st.top()<<endl;
        }

        // nums1 and nums2 ka part now
        // find indices of nums1 inside nums2
        vector<int> final_ans;
        for(auto it : nums1)
        {
            final_ans.push_back(mp[it]);
        }
        return final_ans;
    }
};
