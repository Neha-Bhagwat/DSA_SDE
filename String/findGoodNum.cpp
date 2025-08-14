// Question::: You are given a string num representing a large integer. An integer is good if it meets the following conditions:

// It is a substring of num with length 3.
// It consists of only one unique digit.
// Return the maximum good integer as a string or an empty string "" if no such integer exists.

// Example 1:

// Input: num = "6777133339"
// Output: "777"
// Explanation: There are two distinct good integers: "777" and "333".
// "777" is the largest, so we return "777".
// Example 2:

// Input: num = "2300019"
// Output: "000"
// Explanation: "000" is the only good integer.

// 3 <= num.length <= 1000
// num only consists of digits.

class Solution {
public:
    string largestGoodInteger(string num) {
        string ans;
        int largest_digit = 0;

        for(int i = 0; i<num.size()-2; i++)
        {
            //checking the char with the one two after it.
            if((num[i] == num[i+1]) && (num[i+1] == num[i+2]))
            {
                if(largest_digit <= num[i]-'0')
                {
                    largest_digit = num[i]-'0';
                    ans = num.substr(i, 3);
                }
            }
        }
        return ans;
    }
};
