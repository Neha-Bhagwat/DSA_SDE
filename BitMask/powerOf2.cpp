class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(__builtin_popcount(n) == 1 && n>0) return true;
        else return false;
        //can also do this
        // return ((n & (n-1)) == 0);
    }
};
