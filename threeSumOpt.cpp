class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //best approach is a two pointer approach, just a bit smarter.
        //we will have 3 poointers i, j and k, out of which i is fixed while j and k move in one iteration of i
        //initialize answer list
        vector<vector<int>> answer;
        //first, we sort the array
        sort(nums.begin(), nums.end());    
        int n = nums.size();
        //then make a outer loop for i 
        for(int i=0; i<n; i++)
        {
            if(i>0 && nums[i]==nums[i-1]) continue;
            int left = i+1;
            int right = n-1;
            while(left<right) //no equal sign as we wont let elements repeat
            {
                int sum = nums[i]+nums[left]+nums[right];
                if(sum == 0)
                {
                    //store the answer and move both the left and right by one
                    answer.push_back({nums[i], nums[left], nums[right]});
                    left++;
                    right--;
                    //we do this to avoid checking the same numbers
                    while( left<right && (nums[left] == nums[left-1])) left++;
                    while( left<right && (nums[right] == nums[right+1])) right--;
                }
                else if(sum > 0)
                {
                    //if the answer is greater than needed, reduce right one as it is sorted
                    right--;
                }
                else
                {
                    left++;
                }
        
            }
        }
        return answer;
    }
};
