class Solution {
public:
    void bfs(vector<vector<int>>& mat, vector<vector<int>>& vis)
    {
        int m = mat.size();
        int n = mat[0].size();
        queue<pair<pair<int,int>, int>> q;
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(mat[i][j] == 0)
                {
                    q.push({{i,j}, 0});
                    cout<<i<<" "<<j<<" "<<0<<endl;
                    vis[i][j] = 1;
                }
            }
        }

        while(!q.empty())
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int count = q.front().second;

            q.pop();

            //now check all the 4 directions and do bfs on them as well
            vector<int> drow = {-1, 1, 0, 0};
            vector<int> dcol = {0, 0, -1, 1};

            vector<int> nrow(4, 0);
            vector<int> ncol(4, 0);

            for(int i = 0; i < 4; i++)
            {
                nrow[i] = drow[i] + r;
                ncol[i] = dcol[i] + c;
            }

            //for pushing into the q
            for(int i = 0; i < 4; i++)
            {
                if(nrow[i] >= 0 && ncol[i] >= 0 && ncol[i] < n && nrow[i] < m && vis[nrow[i]][ncol[i]] == 0)
                {
                    // push into the queue
                    q.push({{nrow[i], ncol[i]}, count+1});
                    cout<<nrow[i]<<" "<<ncol[i]<<" "<<count+1<<endl;
                    // visit it with the count
                    vis[nrow[i]][ncol[i]] = count+1;
                }
            }
        }
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        // initialize the vis arr
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));

        // run bfs
        bfs(mat, vis);

        // change the visited ones to 0 correctly
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(mat[i][j] == 0)
                {
                    vis[i][j] = 0;
                }
            }
        }
        return vis;
    }
};
