//the better solution would be to first reverse the entire string, then find words using 2 pointers, then reverse the words found and add them to the string saying temp += word. temp += ' ' to add the space
//after that pop_back() to remove the last trailing space.

class Solution {
public:
    string reverseWords(string s) 
    {
        string temp;
        int start = 0, end;
        for(int start = 0; start < s.size(); start++)
        {
            while(start<s.size() && s[start] == ' ')
            {
                //keep inc start until we reach a character
                start++;
            }
            if(start>=s.size()) break;

            end = start+1;
            while(end < s.size() && s[end] != ' ')
            {
                end++;
            }
            //now we make the word
            if(temp.size() == 0) 
            {
                temp += s.substr(start,end-start);
            }
            else 
            {
                temp = s.substr(start, end-start) + " " + temp;
            }
            //take start back to the first space
            start = end;
        }
        return temp;
    }
};
