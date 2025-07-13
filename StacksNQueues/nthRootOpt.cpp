//finding nth root using recursion
class Solution {
public:
  int NthRoot(int N, int M) 
  {
    //first, we have an sequence from 1 to M
    int high = M;
    int low = 1;
    while(low<=high)
    {
      int mid = (low+high)/2;
      if(pow(mid, N) == M)
      {
        return mid;
      }
      else if(pow(mid, N) > M)
      {
        high = mid-1;
      }
      else
      {
        low = mid+1;
      }
    }
    return -1;
  }
     
};
