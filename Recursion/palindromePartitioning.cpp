//Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

// Example 1:

// Input: s = "aab"
// Output: [["a","a","b"],["aa","b"]]
// Example 2:

// Input: s = "a"
// Output: [["a"]]

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<string> ds;
        vector<vector<string>> ans;
        findSubstring(s, 0, ds, ans);
        return ans;
    }

    void findSubstring(string s, int idx, vector<string> &ds, vector<vector<string>> &ans)
    {
        //base case
        if(idx == s.length())
        {
            ans.push_back(ds);
            return;
        }
        //looping
        for(int i = idx; i<s.size(); ++i)
        {
            //if the portion is palindrome
            if(isPalindrome(s, idx, i))
            {
                //add it to the data structure
                ds.push_back(s.substr(idx, 1+i-idx));                
                //calling the function recursively
                findSubstring(s, i+1, ds, ans);
                //backtracking
                ds.pop_back();
            }
        }
    }

    bool isPalindrome(string s,int left,int right)
    {
        while(left<right)
        {
            if(s[left++]!=s[right--])
            {
                return false;
            }
        }
        return true;
    }
};
