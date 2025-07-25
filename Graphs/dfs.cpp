class Solution {
  public:
  
    void dfsRecur(int node, vector<vector<int>>& adj, int visited[], vector<int> &ls)
    {
        //add the node to list and to visited
        visited[node] = 1;
        ls.push_back(node);
        //traverse the graph
        for(auto it:adj[node]) //this means that an iterator will iterate through the vector<int> that is adj[node]
        {
            if(!visited[it]) //if the node is not visited then
            {
                dfsRecur(it, adj, visited, ls);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        //first make visited array
        int visited[adj.size()] = {0};
        //make a list to store dfs in
        vector<int> ls;
        dfsRecur(0, adj, visited, ls);
        return ls;
    }
};
