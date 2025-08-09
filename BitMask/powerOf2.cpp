// Given an integer n, return true if it is a power of two. Otherwise, return false.
// An integer n is a power of two, if there exists an integer x such that n == 2x.


class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(__builtin_popcount(n) == 1 && n>0) return true;
        else return false;
        //can also do this
        // return ((n & (n-1)) == 0);
    }
};
