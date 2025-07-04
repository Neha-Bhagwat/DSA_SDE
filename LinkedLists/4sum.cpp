//sort the damn array first
//keep i and j fixed initially with j = i+1
//k is j+1 and l starts from the back, then we compare sum
//if sum is greater than target, move l back and if it is lesser move k ahead

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        //brute force approach would be to make 4 loops
        //so, the optimal approach would be n^3 approx
        //first, sort the ll 
        sort(nums.begin(), nums.end());
        //first pointer fixed at i and j for now, iterate till end
        int n =nums.size();
        vector<vector<int>> ans;
        for(int i = 0; i<n;i++)
        {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1; j<n ; j++)
            {
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                //meanwhile l and k move, one from beginning and the other from the end
                int k = j+1;
                int l = n-1;
                while(k<l)
                {
                    long long sum = nums[i];
                    sum+= nums[j];
                    sum+= nums[k];
                    sum+= nums[l];
                    if(sum == target)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        ans.push_back(temp);
                        k++;
                        while(k<l && nums[k] == nums[k-1])
                        {
                            k++;
                        }
                        l--;
                        while(k<l && nums[l] == nums[l+1])
                        {
                            l--; 
                        }
                    }
                    else if(sum > target)
                    {
                        l--;
                    }
                    else //when target is greater than sum
                    {
                        k++;
                    }
                }
            }
        }
        return ans;
    }
};
