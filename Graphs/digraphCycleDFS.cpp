class Solution {
public:
    void createAdj(vector<vector<int>>& prerequisites, vector<vector<int>>& adjList)
    {
        int E = prerequisites.size();
        for(int i = 0; i < E; i++)
        {
            int u = prerequisites[i][0], v = prerequisites[i][1];
            adjList[u].push_back(v);
        }
    }
    bool dfs(vector<vector<int>>& adjList, vector<int>& vis, vector<int>& pathVis, int node)
    {
        vis[node] = 1;
        pathVis[node] = 1;
        // recursion for all adj nodes
        for(auto adjNode : adjList[node])
        {
            if(!vis[adjNode]) {
                // only return for a downstream true
                if(dfs(adjList, vis, pathVis, adjNode)) return true;
            } 
            // cycle condition, if it is visited and pathVisited
            else if(vis[adjNode] == 1 && pathVis[adjNode] == 1) 
            {
                return true;
            }
        }
        //after the path of one node is traversed, reset it
        pathVis[node] = 0;
        // cout<<"pathVis is "<<pathVis[node]<<endl;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int E = prerequisites.size();
        vector<vector<int>> adjList(numCourses);
        vector<int> vis(numCourses,0);
        vector<int> pathVis(numCourses,0);
        createAdj(prerequisites, adjList);

        // run dfs
        for(int i = 0; i < numCourses; i++)
        {
            if(!vis[i])
            {
                if(dfs(adjList, vis, pathVis, i) == true)
                {
                    return false;
                }
            }
        }
        return true;
    }
};
