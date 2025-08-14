class Solution {
  public:
    bool isEven(int n) {
        // using bitwise XOR
        // int temp = n ^ 1;
        // if(temp>n) return true;
        // else return false;
        
        // using bitwise AND
        // return ((n & 1)!=0);
        
        //using bitwise OR
        int temp = n | 1;
        return (n != temp);
        
        
    }
};
