class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        int n = s.size();
        for(int i = 0; i < s.size(); i++)
        {
            //if i, check if X or V is next, then sub 1
            if(s[i] == 'I')
            {
                if(i < n-1 && (s[i+1] == 'X' || s[i+1] == 'V'))
                {
                    ans--;
                }
                //else add 1
                else ans++;
            }

            //if V, add 5
            else if(s[i] == 'V') ans = ans+ 5;

            //if X, sub 10 if next is L or C
            else if(s[i] == 'X')
            {
                if(i < n-1 && (s[i+1] == 'L' || s[i+1] == 'C'))
                {
                    ans =ans - 10;
                }
                //else add 10
                else
                {
                    ans = ans + 10;
                }
            }

            //if L, add 50
            else if(s[i] == 'L') ans = ans+50;

            // if C, sub 100 if next is D or M
             else if(s[i] == 'C')
            {
                if(i < n-1 && (s[i+1] == 'D' || s[i+1] == 'M'))
                {
                    ans =ans - 100;
                }
                //else add 100
                else
                {
                    ans =ans + 100;
                }
            }
            
            // if D, add 500
            else if(s[i] == 'D') ans =ans + 500;

            // if M, add 1000
            else ans =ans + 1000;
        }
        return ans;
    }
};
