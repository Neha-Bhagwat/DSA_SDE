// 1631. Path With Minimum Effort
(* You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort.
A route's effort is the maximum absolute difference in heights between two consecutive cells of the route.
Return the minimum effort required to travel from the top-left cell to the bottom-right cell.

Example 1:
Input: heights = [[1,2,2],[3,8,2],[5,3,5]]
Output: 2
Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells.
This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3.

Example 2:
Input: heights = [[1,2,3],[3,8,4],[5,3,5]]
Output: 1
Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5].

Example 3: *)
//Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]
//Output: 0
//Explanation: This route does not require any effort. 

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        priority_queue<pair<int, pair<int,int>>, vector<pair<int, pair<int,int>>>, greater<pair<int, pair<int,int>>>> pq;
        vector<vector<int>> effort(n, vector<int>(m,1e9));

        pq.push({0,{0,0}});
        effort[0][0] = 0;
        while(!pq.empty())
        {
            int diff = pq.top().first;
            int x = pq.top().second.first, y = pq.top().second.second;
            // check whether the entry is old right here
            vector<int> dx = {-1,1,0,0};
            vector<int> dy = {0,0,-1,1};
            pq.pop();
            if(effort[x][y] < diff) continue;
            // neighbours
            for(int i = 0; i < 4; i++)
            {
                int r = dx[i] + x, c = dy[i] + y;
                if(r >= 0 && r < n && c >= 0 && c < m)
                {
                    // if it is valid, we can try going
                    int newEffort = max(effort[x][y], abs(heights[r][c]-heights[x][y]));
                    // cout<<r<<" "<<c<<" "<<newEffort<<endl;
                    if(effort[r][c] > newEffort)
                    {
                        effort[r][c] = newEffort;
                        pq.push({effort[r][c],{r,c}});
                    }
                    // we dont go if it aint worth it
                }
            }
        }
        return effort[n-1][m-1];
    }
};
