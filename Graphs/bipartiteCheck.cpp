class Solution {
public:
    bool bfs(queue<int> q, vector<vector<int>>& graph, vector<int>& vis, int node)
    {
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            // iterate through all the adjacent ones
            for(int i = 0; i < graph[node].size(); i++)
            {
                int adjNode = graph[node][i];
                cout<<" The parent node is "<<node<<" and the adj node is "<<adjNode<<endl;
                int color;
                // check if any adj ones have same color
                if(vis[adjNode] == vis[node])
                {   
                    cout<<"Here colors of adjacents are same "<<vis[node]<<" and "<<vis[adjNode];
                    return false;
                }
                // if it is not visited
                if(!vis[adjNode])
                {
                    // new colour is
                    if(vis[node] == 1) color = 2;
                    else color = 1;
                    // run bfs by pushing to queue
                    q.push(adjNode);
                    // add proper color to visited array
                    vis[adjNode] = color;
                }
            }
        }
        // if they are not coloured, assign the other colour

        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        // make visited vector
        int m = graph.size();
        vector<int> vis(m,0);
        // make queue for bfs
        queue<int> q;
        bool ans = true;
        for(int i = 0; i < graph.size(); i++)
        {
            if(!vis[i])
            {
                q.push(i);
                vis[i] = 1;
                ans = ans & bfs(q, graph, vis, i);
            }    
        }
        return ans;
    }
};
