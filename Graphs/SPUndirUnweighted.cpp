// This is done on GFG, where int main initializes the graph. Adj List and BFS is done in the shortestPath function.
#include <bits/stdc++.h>
using namespace std;

// DFS function to explore all possible paths
int shortestPath(int V, vector<vector<int>> &edges, int src, int dest) {

    // Step 1: Build adjacency list
    vector<vector<int>> adj(V);

    for (auto &e : edges) {
        int u = e[0];
        int v = e[1];

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Step 2: Initialize visited array
    vector<int> vis(V, 0);

    // Stores the shortest distance found so far
    int ans = INT_MAX;

    // Step 3: Start BFS from source vertex
  	queue<int> q;
  	q.push(0);
  // here dist from 0 should be 0, but we have kept it as 1 for now.
  	vis[0] = 1; //this will act as a flag as well as a storage for distance. 
  	
  	while(!q.empty())
    {
      int node = q.front();
      q.pop();
      for(int adjNode : adj[node])
      {
       	 if(vis[adjNode] == 0)
         {
           	q.push(adjNode);
          	vis[adjNode] = vis[node]+1; 
         }
      }
    }
  	ans = vis[dest]-1; // if vis[dest] is 0, then ans will be -1
    return ans;
}

int main() {

    int V = 9;


    vector<vector<int>> edges = {
        {0, 1},
        {0, 3},
        {1, 2},
        {3, 4},
        {4, 5},
        {2, 6},
        {5, 6},
        {6, 7},
        {6, 8},
        {7, 8}
    };

    int src = 0;
    int dest = 8;

    cout << shortestPath(V, edges, src, dest) << endl;

    return 0;
}
