class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // form indegrees
        vector<int> indegree(numCourses,0);
        vector<int> ans;
        vector<int> vis(numCourses,0);
        vector<vector<int>> adjList(numCourses);
        
        // make adj list and popu
        
        for(int i = 0; i < prerequisites.size(); i++)
        {
            int u = prerequisites[i][0], v = prerequisites[i][1];
            indegree[v]++;
            adjList[u].push_back(v);
        }
        
        // insert all nodes with indegree 0 into the queue
        queue<int> q;
        for(int i = 0; i < numCourses; i++)
        {
            if(indegree[i] == 0) 
            {
                q.push(i);
                vis[i] = 1;
            }
        }
        
        while(!q.empty())
        {
            int node = q.front();
            ans.push_back(node);
            q.pop();
            
            for(int adjNode : adjList[node])
            {
                // reduce indegree of all adj nodes
                indegree[adjNode]--;
                // then add anything with indegree 0 back into if not visited
                cout<<node<<" "<<adjNode<<" "<<indegree[adjNode]<<endl;
            }
            
            bool pushed = false;
            for(int i = 0; i < numCourses; i++)
            {
                if(indegree[i] == 0 && vis[i] == 0) 
                {
                    q.push(i);
                    vis[i] = 1;
                    cout<<i<<endl;
                }
            } 
        }

        // if all the nodes are visited, then it works otherwise it does not
        for(int i = 0; i < numCourses; i++)
        {
            if(!vis[i]) return false;
        }
        return true;

    }
};
