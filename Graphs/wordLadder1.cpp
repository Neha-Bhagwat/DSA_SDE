class Solution {
public:
    int bfs(queue<pair<string, int>> &q, unordered_set<string> uset, vector<string>& wordList, string endWord)
    {
        while(!q.empty())
        {
            // get the word from queue
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word == endWord) return steps;
            // remove the word from set
            uset.erase(word);
            for(int i = 0 ; i < word.size(); i++)
            {
                char og = word[i];
                // change all the letters in the word from a to z
                for(char ch = 'a'; ch <= 'z'; ch++)
                {
                    // getting new word here
                    word[i] = ch; 
                    if(uset.find(word) != uset.end())
                    {
                        // word exists in the set, push it
                        q.push({word, steps+1});
                    }
                }
                // reset the word to its original value
                word[i] = og;
            }
        }
        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        unordered_set<string> uset;
        for(string word : wordList) uset.insert(word);
        // now the start word and other words are in the set and the queue is done
        return bfs(q, uset, wordList, endWord);
    }
};
