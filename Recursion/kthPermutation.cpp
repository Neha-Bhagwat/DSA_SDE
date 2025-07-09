//bf: use recursion to generate all the permutations and store them somewhere. then sort that (if needed, accd to your logic)
    //TC->O(n!*n), the other n is for the deepcopy + O(n!*log(n!)) for sorting
#include<string.h>
class Solution {
public:
    string getPermutation(int n, int k) {
        //my logic. 
        //first, calculate n factorial
        int fact = 1;
        //first make the array of 1...n
        vector<int> digits;
        string ans="";
        for(int i = 1; i<n;i++)
        {
            fact = fact*i;
            digits.push_back(i);
        }
        digits.push_back(n);
        //now fact is ready. we need the kth permutation, which from 0 indexing is k-1th one. 
        k--;
        //for first element, lets find k/(n-1)! th element
        for(int i=0; i<n; i++)
        {
            int index = k/fact;
            ans = ans+to_string(digits[index]);
            digits.erase(digits.begin()+index);
            if(digits.size()==0) break;
            //now to get the next digit, we will need to find the remainder of k with the n-1!.
            k = k % fact;
            fact /= digits.size();
        }
        return ans;
    }
};

//learnings, dont use digits[i] = something unless you have declared it with specific memory. use push_back if you havent used no of characters.
//learnings, always do code dry runs
//TC->O(n^2)
//SC->O(2n) --to store ans and to store those 1....n digits 
