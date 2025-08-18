// Given an undirected graph with V vertices and E edges, represented as a 2D vector edges[][], where each entry edges[i] = [u, v] denotes an edge between vertices u and v, determine whether the graph contains a cycle or not. The graph can have multiple component.

// Input: V = 4, E = 4, edges[][] = [[0, 1], [0, 2], [1, 2], [2, 3]]
// Output: true
// Explanation: 
// 1 -> 2 -> 0 -> 1 is a cycle.

class Solution {
public:
    //first create an adjacency list
    vector<vector<int>> createAdj(int V, vector<vector<int>>& edges)
    {
        vector<vector<int>> adj(V);
        for(auto it: edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        return adj;
    }

    //then make a logic to look for cycles
    bool checkCycle(int node, int V, vector<vector<int>> &adj, vector<int> &visited)
    {
        
        queue<vector<int>> q;
        //vector<int> visited(V, 0);
        visited[node] = 1;
        q.push({node, -1});
        while(!q.empty())
        {
            vector<int> temp = q.front();
            int node = temp[0];
            int prev = temp[1];
            q.pop();
            for(auto it: adj[node])
            {
                if(visited[it] == 0)
                {
                    visited[it] = 1;
                    q.push({it, node});
                    // cout<<"When visited is 0, it is "<<it<<" prev is "<<prev<<" node is "<<node<<endl;
                }
                else if(it != prev)
                {
                    // cout<<"When visited is 1, it is "<<it<<" prev is "<<prev<<" node is "<<node<<endl;
                    return true;
                }
            }
        }
        return false;
    }

    //the function where we call each vertex to look for a cycle in it
    bool isCycle(int V, vector<vector<int>>& edges) 
    {
        int n = V;

        vector<vector<int>> adj = createAdj(V, edges);
        
        vector<int> visited(V, 0);
        //add all elements one by one
        
        for(int i = 0; i < V; i++)
        {
            if (!visited[i]) 
            {
                if(checkCycle(i, V, adj, visited))
                    return true;
            }
        }
        return false;
        
    }
};
