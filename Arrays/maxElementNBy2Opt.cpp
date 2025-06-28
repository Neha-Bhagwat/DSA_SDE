#include<bits/stdc++.h>
class Solution {
//this uses moore's voting algorithm, where we count the frequency and try to find if there is an element with the appropriate amount of votes. 
//if votes drop to 0, we set the voting for a new number. then repeat the same thing.
//if votes are not 0 by the end, we confirm whether that number is the winner or not, depending on the count of number of times it occurs in the array
public:
    int majorityElement(vector<int>& nums) {
        //moore's voting algo
        //here, we check the counter 
        int n = nums.size();
        int el = 0, cnt = 0;
        for(int i = 0; i < n; i++)
        {
            if(cnt == 0)
            {
                el = nums[i];
                cnt = 1;
            }
            else if(nums[i] == el)
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }
        //now to check if the el is the right value
        cnt = 0;
        for(int i =0; i < n; i++)
        {
            if(el == nums[i])
            {
                cnt++;
            }
        }
        if(cnt++ > n/2)
        {
            return el;
        }
        return -1;
    }
};
