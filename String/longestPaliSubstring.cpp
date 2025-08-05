//Given a string s, return the longest palindromic substring in s.

// Example 1:
// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.

// Example 2:
// Input: s = "cbbd"
// Output: "bb"

//here, the logic used is tracking of the centre of the palindrome, then iterating left and right until the two characters arent equal
//we use two loops, one for the case that the palindrome is even in size and the other one when palindrome is odd in size

class Solution {
public:
    string longestPalindrome(string s) {
        //logic
        //check the cases where the palindrome is an odd length
        int count = 0, n = s.size();
        int right, left;
        int boundR, boundL;
        for(int i = 0; i < n; i++)
        {
            right = i;
            left = i;
            while(left >=0 && right<n && s[left] == s[right]  )
            {
                right++;
                left--;
                if(count < right-left-1)
                {
                    count = right-left-1;
                    boundR = right-1;
                    boundL = left+1;
                }
            }
        }
        //case where even length
        for(int i = 0; i < n; i++)
        {
            right = i+1;
            left = i;
            while(left >=0 && right<n && s[left] == s[right])
            {
                right++;
                left--;
                if(count < right-left-1)
                {
                    count = right-left-1;
                    boundR = right-1;
                    boundL = left+1;
                }
            }
        }
        string word = s.substr(boundL, boundR-boundL+1);
        return word;
    }
};
