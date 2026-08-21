//this solution is not entirely correct. it fails to return neither for cases like 1.1.1.1.1 or 2:2:2:2:2:2:2:2:2:2:2:2:2


// Validate IP Address
// Problem statement
// Source note: The timed assessment linked this exact task. The judged core task matches the visible report at about 99%.

// Given a string queryIP, return "IPv4" if it is a valid IPv4 address, "IPv6" if it is a valid IPv6 address, or "Neither" otherwise.

// IPv4 rules
// The address contains exactly four decimal segments separated by ..
// Each segment is an integer from 0 through 255.
// A segment has no leading zero unless it is exactly 0.
// Every character in a segment is a decimal digit.
// IPv6 rules
// The address contains exactly eight groups separated by :.
// Each group contains one to four hexadecimal characters.
// Hexadecimal letters may be lowercase or uppercase.
// Leading zeroes are allowed, but an empty group is not.
// Function
// validIPAddress(queryIP: String) → String
// Examples
// Example 1
// queryIP = "172.16.254.1"
// return = "IPv4"
// The address has four decimal segments, each is in range, and none has an invalid leading zero.

// Example 2
// queryIP = "2001:0db8:85a3:0:0:8A2E:0370:7334"
// return = "IPv6"
// The address has eight non-empty hexadecimal groups, and every group contains at most four characters.

// Example 3
// queryIP = "256.256.256.256"
// return = "Neither"
// Every segment is greater than 255, so this is not a valid IPv4 address.

// Constraints
// queryIP is a non-empty string.
// queryIP contains only English letters, decimal digits, ., and :.

  
class Solution {
public:
  string validIPAddress(string queryIP) 
{
    int pos = 0;
    vector < string > segments;
    int lastPos = 0;
    pos = queryIP.find(".");
    if (pos != -1) {
        for (int i = 0; i < 4; i++)
        {
            cout<<i<<endl;
            pos = queryIP.find(".");
            if (pos != -1 || i == 3)
            {
                
                // then it is a IPv4 addr or wrong
                int len = 1;
                if (pos != -1)
                {
                    queryIP[pos] = 'x';
                    len = pos - lastPos;
                    segments.push_back(queryIP.substr(lastPos, len));
                }
                else
                {
                    // will give till the end
                    segments.push_back(queryIP.substr(lastPos));
                }
                int number = 0;

                if (len == 0 || len > 3) return "Neither";
                // convert to a number
                for (int j = 0; j < len; j++)
                {
                    //make into a decimal
                    number *= 10;
                    number += (int)segments[i][j] - (int)'0';
                    // if the added thing isnt a single digit
                    if ((segments[i][j] - '0') < 0 || (segments[i][j] - '0') > 9)
                    {
                        return "Neither";
                    }
                }
                // now u have ur num
                if (number != 0)
                {
                    if (segments[i][0] == '0') return "Neither";
                }
                else if(len != 1) return "Neither"; //handles the case where multiple 0s are present.
                if (number > 255) return "Neither";
                // you will either return ipv4 here or neither
            }
            lastPos = pos+1;
        }
        return "IPv4";
    }
    // if that isnt the case
    pos = queryIP.find(":");
    int len;
    if (pos != -1)
    {
        // extract them all 
        for (int i = 0; i < 8; i++)
        {
            pos = queryIP.find(":");
            if (pos != -1 || i == 7)
            {
                len = 1;
                if (pos != -1)
                {
                    queryIP[pos] = 'x';
                    len = pos - lastPos;
                    segments.push_back(queryIP.substr(lastPos, len));
                }
                else
                {
                    // will give till the end
                    segments.push_back(queryIP.substr(lastPos));
                }
            }
            // if len is 0 or more than 4 return neither
            // check for either empty groups
            if (len == 0 || len > 4) return "Neither";
            for (int j = 0; j < len; j++)
            {
                // make sure all letters are correct -> a, b, c, d, e, f, A, B, C, D, E, F, 0, 1, 2, 3, 4, 5, 6, 7, 8 ,9
                if (segments[i][j] == 'a' || segments[i][j] == 'b' || segments[i][j] == 'c' || segments[i][j] == 'd' || segments[i][j] == 'e' || segments[i][j] == 'f' || segments[i][j] == 'A' || segments[i][j] == 'B' || segments[i][j] == 'C' || segments[i][j] == 'D' || segments[i][j] == 'E' || segments[i][j] == 'F' || segments[i][j] == '0' || segments[i][j] == '1' || segments[i][j] == '2' || segments[i][j] == '3' || segments[i][j] == '4' || segments[i][j] == '5' || segments[i][j] == '6' || segments[i][j] == '7' || segments[i][j] == '8' || segments[i][j] == '9')
                {
                    continue;
                }
                else
                {
                    return "Neither";
                }
            }
            lastPos = pos+1;
        }
        return "IPv6";
    }
    return "Neither";
}
};
