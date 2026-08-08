#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> topoSort(vector<vector<int>>& adj) {
    int n = adj.size();
    vector<int> indegree(n,0);
    vector<int> vis(n, 0);
  
  	for(int i = 0; i < n; i++)
    {
      for(int adjNode : adj[i])
      {
        indegree[adjNode]++;
      }
    }

	queue<int> q;
    for (int i = 0; i < n; i++) {
        if(indegree[i] == 0)
        {
         	q.push(i); 
        }
    }
  
  	vector<int> topo;
  
  	while(!q.empty())
    {
        int node = q.front();
      	topo.push_back(node);
        q.pop();
        for(int adjNode : adj[node])
        {
          // reduce indegree of all the adjNodes by 1
          indegree[adjNode]--;
          // insert into q if degree is 0
          if(indegree[adjNode]==0) q.push(adjNode);
        }
    }
    return topo;
}
