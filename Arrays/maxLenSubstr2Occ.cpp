class Solution {
public:
    int maximumLengthSubstring(string s) {
        map<char, int> mp;
        int start = 0, finish = 0, maxLen = 1, n = s.size();
        
        // insert the starting element
        mp[s[start]]++;
        while(finish < n-1)
        {
            // inc finish and add to map
            finish++;
            mp[s[finish]]++;
            
            // if map is full, iterate till start reaches the right value, removing elements.
            if(mp[s[finish]]>2) 
            {
                // move s[start], removing everything
                char val = s[finish]; 
                while(s[start] != val)
                {
                    mp[s[start]]--;
                    start++;
                }
                // until you cross the first s[finish]
                mp[s[start]]--;
                start++;
            }
            
            maxLen = max(maxLen, finish-start+1);
        }
        return maxLen;
    }
};
