class Solution {
public:
    int hammingWeight(int n) {
      return(__builtin_popcount(n));
    // another way of solving the problem  
    //     int count = 0;
    //     while(n > 1)
    //     {
    //         if(n%2 == 1) count++;
    //         n = n/2;
    //     }
    //     if(n == 1)count++;
    //     return count;
    // }
};
