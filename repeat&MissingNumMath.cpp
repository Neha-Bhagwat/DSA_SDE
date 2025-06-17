class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        int n = nums.size();
        long long missing;
        long long repeating;
        vector<int> answer(2,0);
        int Sn = n*(n+1)/2;
        long long Sn2 = n*(n+1)*(2n+1)/6;
        long long S1n = 0;
        long long S1n2 = 0;
        //now lets find of sum and sum of squares of array
        for(int i =0; i<n; i++)
        {
            S1n += (long long)nums[i];
            S1n2 += (long long)nums[i]*(long long)nums[i];
        }
        //now, we have 2 equations. 
        //x-y = S1n-Sn
        //x+y = S1n2-Sn2/(x-y)
        //x = (S1n-Sn)/2 + (S1n2-Sn2)/2(S1n-Sn)
        //y = (S1n2-Sn2)/2(S1n-Sn) - (S1n-Sn)/2
        repeating = (S1n-Sn)/2 + (S1n2-Sn2)/(2*(S1n-Sn))
        missing = (S1n2-Sn2)/(2*(S1n-Sn)) - (S1n-Sn)/2
        answer[0] = (int)repeating;
        answer[1] = (int)missing;
        return answer;
    }
};
//HERE, NEXT TIME SE, PLS DO THE INTERMEDIATE STEPS TO AVOID ERRORS.
//also, you can return vectors like this {(int)repeating,(int)missing} to simplify matters.
//Time complexity-> O(n)
//Space complexity-> O(1)
