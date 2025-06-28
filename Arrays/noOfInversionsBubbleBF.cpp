class Solution {
public:
   long long int numberOfInversions(vector<int> nums) {
      //this uses bubble sort algo repurposed for counting inversions
        long long int n = nums.size();
        long long int noInversion = 0;
        for(long long int i = 0; i < n ; i ++)
        {
            for ( long long int j = i; j<n; j++)
            {
                if(nums[i] > nums[j]) //checking condition for inversion
                {
                    noInversion++; //incrementing counter
                }
            }
        }
        return noInversion;
    }
};
