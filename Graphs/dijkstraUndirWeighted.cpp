class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        
        vector<vector<pair<int,int>>> adjList(V);
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        // make adj list
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            adjList[u].push_back({v, w});
            adjList[v].push_back({u, w});
        }
        
        // init pq -> dist, node
        pq.push({0, src});
        vector<int> dist(V, 1e9);
        dist[src] = 0;
        while(!pq.empty())
        {
            int distFromSrc = pq.top().first;
            int node = pq.top().second;
            // cout<<node<<" "<<distFromSrc<<" "<<typeid(node).name()<<endl;
            pq.pop();
            
            // now go to neighbours
            for(auto it : adjList[node])
            {
                int weight = it.second;
                int adjNode = it.first;
                if(distFromSrc+weight < dist[adjNode])
                {
                    dist[adjNode] = distFromSrc + weight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
            
        }
        return dist;
    }
};
