//Set the rightmost unset bit
// Difficulty: BasicAccuracy: 47.64%Submissions: 67K+Points: 1
// Given a non-negative number n . The problem is to set the rightmost unset bit in the binary representation of n.

// Examples :

// Input: n = 6
// Output: 7
// Explanation: The binary representation of 6 is 110. After setting right most bit it becomes 111 which is 7.
// Input: n = 15
// Output: 31
// Explanation: The binary representation of 15 is 01111. After setting right most bit it becomes 11111 which is 31.
// Expected Time Complexity: O(Logn)
// Expected Auxiliary Space: O(1)

class Solution {
  public:
    int setBit(int n) {
        //count the number of times you need to do a rightshift to get a no div by 2
        
        int count = 0;
        int temp = n;
        
        while(temp%2 != 0 && temp != 0)
        {
            temp = temp>>1; //how many times will you forget to equate temp with temp>>1
            count++;
        }
        
        //after that, 2^count ke saath OR kardo.
        int twoPow = pow(2, count);
        return (n | twoPow);
    }
};
