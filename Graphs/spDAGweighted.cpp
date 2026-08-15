class Solution {
  public:
    void dfs(int node, vector<vector<pair<int,int>>>& adjList, stack<int>& st, vector<int>& vis)
    {
        vis[node] = 1;
        for(pair<int,int> adjNode : adjList[node])
        {
            if(vis[adjNode.first] == 0) dfs(adjNode.first, adjList, st, vis);
        }
        st.push(node);
    }
    
    vector<int> shortestPath(int V, vector<vector<int>>& edges) 
    {
        vector<vector<pair<int,int>>> adjList(V);
        vector<int> vis(V);
        stack<int> st;
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1], weight = edges[i][2];
            adjList[u].push_back({v, weight});
        }
        
        for(int i = 0; i < V; i++)
        {
            if(!vis[i])
            {
                dfs(i, adjList, st, vis);
            }
        }
        
        
        // now the stack is populated.
        vector<int> dis(V, INT_MAX);
        dis[0] = 0;
        
        // pop the top of the stack and find dist of adj nodes
        while(!st.empty())
        {
            int node = st.top();
            // cout<<node<<endl;
            // find dist to adj
            if(dis[node] != INT_MAX)
            {
                for(auto adjNodes : adjList[node])
                {
                    dis[adjNodes.first] = min(dis[adjNodes.first], dis[node] + adjNodes.second);
                    // cout<<adjNodes.first<<" "<<dis[adjNodes.first]<<endl;
                }
            }
            st.pop();
        }
        
        for(int i = 0; i < V; i++)
        {
            if(dis[i] == INT_MAX) dis[i] = -1;
        }
        
        return dis;
    }
};
