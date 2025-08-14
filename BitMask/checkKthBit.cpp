//Given two positive integer n and  k, check if the kth index bit of n is set or not.
// Note: A bit is called set if it is 1. 
// Constraints:
// 1 ≤ n ≤ 109
// 0 ≤ k ≤ 31

class Solution {
  public:
    bool checkKthBit(int n, int k) {
        //do a right shift and check divisibility by 2
        n=n>>k;
        return (n%2==1);
        
        //or else another approach is taking and with 1.
        // n = n>>k;
        // return ((n & 1) != 0);
    }
};
