class Solution {
public:
    vector<int> findMissingRepeatingNumbers(vector<int> nums) {
        int n = nums.size();
        //this is the xor method
        int xr = 0
        //s1: you xor the array nos and nos from 1 to n
        for(int i =0; i < n; i++)
        {
            xr = xr ^ nums[i];
            xr = xr ^ (i+1);
        }

        //s2: you find the bitno where there is a 1, indicating a difference there
        int bitNo = 0;
        while(1)
        {
            //here, we and xr with powers of 2 using leftshift
            if((xr & (1<<bitNo)) != 0)
            {
                break;
            }
            bitNo++; //incrementing bitno
        }

        //s3: you divide nos into zeroes and ones and xor them separately
        int zeros = 0;
        int ones = 0;
        for(int i = 0 ; i < n ; i++)
        {
            if((nums[i] & (1<<bitNo)) == 0)
            {
                zeroes = zeroes ^ nums[i];
            }
            else
            {
                ones = ones ^ nums[i];
            }
        }

        for(int i = 1 ; i <= n ; i++)
        {
            if((nums[i] & (1<<bitNo)) == 0)
            {
                zeroes = zeroes ^ i;
            }
            else
            {
                ones = ones ^ i;
            }
        }
        //this will give zeroes as one thing and ones as another

        //s5: check in the array what is the count of zero number and return
        for(int i = 0 ; i < n ; i++)
        {
            if(nums[i] == zeroes) 
            {
                cntr++;
            }
        }
        if(cntr == 2){
            return {zeroes, ones}
        }
        return {ones, zeroes}
    }
};
