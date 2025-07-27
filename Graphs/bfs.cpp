class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        //logic to be written here
        //first we have a visted array
        vector<int> visited(adj.size(), 0);
        vector<int> bfs;
        //now, initnially we push 0. so for that, 
        visited[0] = 1;
        //initialize queu
        queue<int> q;
        q.push(0);
        //now we pop it from queue
        
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            bfs.push_back(node);
            //now we check for all the neighbours of q and all their neighbours as well
            for(auto it : adj[node])
            {
                //if the node isnt visited yet then push it and let the loop run over and over until the queu is empty
                if(visited[node]==0)
                {
                    q.push(node);       
                }
            }
            
        }
        
    }
};
