// Given a sorted dictionary of an alien language having N words and K starting alphabets of a standard dictionary. Find the order of characters in the alien language.
// There may be multiple valid orders for a particular test case, thus you may return any valid order as a string. The output will be True if the order returned by the function is correct, else False denoting an incorrect order. If the given arrangement of words is inconsistent with any possible letter ordering, return an empty string "".

// Example 1
// Input: N = 5, K = 4, dict = ["baa","abcd","abca","cab","cad"]
// Output: b d a c
// Explanation: 
// We will analyze every consecutive pair to find out the order of the characters.
// The pair “baa” and “abcd” suggests ‘b’ appears before ‘a’ in the alien dictionary.
// The pair “abcd” and “abca” suggests ‘d’ appears before ‘a’ in the alien dictionary.
// The pair “abca” and “cab” suggests ‘a’ appears before ‘c’ in the alien dictionary.
// The pair “cab” and “cad” suggests ‘b’ appears before ‘d’ in the alien dictionary.
// So, [‘b’, ‘d’, ‘a’, ‘c’] is a valid ordering.

// Example 2
// Input: N = 3, K = 3, dict = ["caa","aaa","aab"]
// Output: c a b
// Explanation: Similarly, if we analyze the consecutive pair 
// for this example, we will figure out [‘c’, ‘a’, ‘b’] is 
// a valid ordering.

class Solution {
public:
	string findOrder(string dict[], int N, int K) {
		// first create the adj list
        vector<vector<int>> adjList(K);
        vector<int> indegree(K);
        for(int i = 0; i < N-1; i++)
        {
            // for every 2 words, check the differentating characters
            for(int j = 0; j < min(dict[i].size(), dict[i+1].size()); j++)
            {
                if(dict[i][j] != dict[i+1][j])
                {
                    // edge i -> i+1 or u -> v
                    int u = dict[i][j] - 'a', v = dict[i+1][j] - 'a';
                    adjList[u].push_back(v);
                    indegree[v]++;
                    break;
                }
            } 
        }

        // now lets do the topo sort
        queue<int> q;
        vector<int> ans;
        for(int i = 0; i < K; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
                ans.push_back(i);
            }
        }

        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(int adjNode : adjList[node])
            {
                indegree[adjNode]--;
                if(indegree[adjNode] == 0)
                {
                    q.push(adjNode);
                    ans.push_back(adjNode);
                }
            }
        }
        string result = "";
        for(int x : ans) result += (char)('a' + x);
        return result;
	}
};
