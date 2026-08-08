void dfsTopo(int node, vector<int>& vis, vector<vector<int>>& adj, stack<int>& st) {
    vis[node] = 1;
  // doing dfs for all adj nodes
  for(int adjNode : adj[node])
  {
    if(!vis[adjNode]) dfsTopo(adjNode, vis, adj, st);
  } 
  st.push(node);
}

vector<int> topoSort(vector<vector<int>>& adj) {
  int v = adj.size();
  vector<int> vis(v, 0);
  stack<int> st;
  // calling dfs topo for each vertex if not visited
  
  for(int i = 0; i < v; i++)
  {
    if(!vis[i]) dfsTopo(i, vis, adj, st); 
  }
  while(!st.empty())
  {
    int val = st.top();
    std::cout<<val<<" ";
    st.pop();
  } 
}
