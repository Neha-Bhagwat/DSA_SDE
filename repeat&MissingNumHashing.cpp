class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        int n = nums.size();
        vector<int> count(n,0);
        vector<int> answer(2,0);
        // we iterate through nums, assigning values to count array accordingly.
        // when we get value of count to be 2 at any point, then we assign that to answer[0]
        for(int i=0; i < n; i++)
        {
            count[nums[i]-1]++;
            if(count[nums[i]-1] == 2)
            {
                answer[0] = nums[i];
            }
        }

        //now to check which is 0, we will iterate through count array
        //then we will assign the value of missing to i+1, since that is how an array is indexed
        for(int i=0; i < n; i++)
        {
            if(count[i] == 0)
            {
                answer[1] = i+1;
                break; //after we figure that out, we do not need to keep the process going
            }
        }
        return answer;
    }
};
//time complexity-> O(2n)
//space complexity-> O(n)
