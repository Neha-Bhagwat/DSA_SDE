// 802. Find Eventual Safe States
// There is a directed graph of n nodes with each node labeled from 0 to n - 1. The graph is represented by a 0-indexed 2D integer array graph where graph[i] is an integer array of nodes adjacent to node i, meaning there is an edge from node i to each node in graph[i].
// A node is a terminal node if there are no outgoing edges. A node is a safe node if every possible path starting from that node leads to a terminal node (or another safe node).
// Return an array containing all the safe nodes of the graph. The answer should be sorted in ascending order.

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // smartest thingie that was there would be to reverse the nodes of graph

        // make adj list
        int V = graph.size();
        vector<int> indegree(V,0);
        vector<vector<int>> adjList(V);
        for(int i=0; i < V; i++)
        {
            int adjNode = i;
            for(int node : graph[i])
            {
                adjList[node].push_back(adjNode);
                indegree[adjNode]++;
            }
        }

        // for(int i=0; i < V; i++)
        // {
        //     for(int j : adjList[i])
        //     {
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        //     cout<<indegree[i]<<"!!"<<endl;
        // }

        vector<int> ans;
        vector<int> vis(V,0);
        // topo sort moment
        // insert into q with indegree 0
        queue<int> q;
        for(int i = 0; i < V; i++)
        {
            if(indegree[i] == 0)
            {
                q.push(i);
                vis[i] =1;
            }
        }

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(int adjNode : adjList[node])
            {
                indegree[adjNode]--;
                if(indegree[adjNode] == 0 && vis[adjNode] == 0)
                {
                    q.push(adjNode);
                    vis[adjNode] =1;
                }
            }
        }

        for(int i = 0; i < V; i++)
        {
            if(vis[i] == 1) ans.push_back(i);
        }
        return ans;
    }
};
