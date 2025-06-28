#include<bits/stdc++.h>
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        //most brute force would be to check every single element, then incerement counter and then check if it is greater than n/2. TC->O(n^2)
        //approach2, creating a hashmap. here TC->O(nlogn+n) SC->O(n)
        int n = nums.size();
        umap<int,int> mpp;
        //here creation will take O(nlogn)
        for(int i = 0; i < n; i++){
            mpp[nums[i]]++;
        }
        
        //traversal will take O(n)
        for(auto it: mpp)
        {
            if(it.second > n/2)
            {
                return it.first;
            }
        }
        return -1;
    }
};
