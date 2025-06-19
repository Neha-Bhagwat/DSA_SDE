class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //first bf solution is that take each element and check it in the array TC->O(n^2)
        //we could only check distinct elements and count. this is bf. return after 2 ones
        //hashing is a method that can be done in linear time, which is good, but again, space required will be O(n), which won't be acceptable
        //somehow, we have to iterate through the array only a few of times and find the answer.

        //okayyy, one major point that i missed. Only 2 such elements can be there at max. so we need to define 2 elements, and anyone other than those elements decrement counters. otherwise, increment the counter of one of them. same method as Moores voting algo
        int cntr1=0, cntr2=0;
        int ele1, ele2;
        int n = nums.size();

    // if either counter is 0, increment it and nums[i]
        for(int i = 0; i < n ; i++)
        {
            if(cntr1 == 0 && nums[i]!=ele2)
            {
                ele1 = nums[i];
                cntr1++;
                
            }
            else if(cntr2 == 0 && nums[i] != ele1)
            {
                ele2 = nums[i];
                cntr2++;
            }
            //if neither are zero, increment cntr1 if nums[i] = ele1
            else if(ele1 == nums[i])
            {
                cntr1++;
            }
            else if(ele2 == nums[i])
            {
                cntr2++;
            }
            //if the element is neither, dec both counters
            else
            {
                cntr1--;
                cntr2--;
            }       
        }

        cntr1 = 0;
        cntr2 = 0;

        //checking if ele1 and ele2 are correct or not
        for(int i = 0; i < n ; i++)
        {
            if(nums[i] == ele1)
            {
                cntr1++;
            }
            else if(nums[i] == ele2)
            {
                cntr2++;
            }
        }

        if((cntr1>(n/3)) && (cntr2>(n/3)))
        {
            return {ele1, ele2};
        }
        else if(cntr1>(n/3))
        {
            return {ele1};
        }
        else if(cntr2>(n/3))
        {
            return {ele2};
        }
        else
        {
            return {};
        }
    }
};
