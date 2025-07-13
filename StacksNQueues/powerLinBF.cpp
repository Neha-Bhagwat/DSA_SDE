class Solution {
public:
  int NthRoot(int N, int M) {
       //first, its easy to do with linear search
      int num = 1;
      int power = 1;
      while(1)
      { 
        power = 1;
        power = pow(num, N);
        if(power == M)
        {
          return num;
        }
        else if(power>M)
        {
          return -1;
        }
        num++;
      }
    }
};
