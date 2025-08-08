//Q. Given an n x n integer matrix grid, return the minimum sum of a falling path with non-zero shifts.
//A falling path with non-zero shifts is a choice of exactly one element from each row of grid such that no two elements chosen in adjacent rows are in the same column.


class Solution {
public:
    // int helper(int idx, int col, vector<vector<int>>& grid, vector<vector<int>>& dp)
    // {
    //     int n = grid.size();
    //     //base case
    //     if(idx == n-1)
    //     {
    //         return grid[idx][col];
    //     }
    //     //it can go from 0 to n-1 but no i
    //     vector<int> pathSums(n, 1e9);
    //     if(dp[idx][col]!=-1) return dp[idx][col];
    //     for(int i = 0; i < n; i++)
    //     {
    //         if(i != col) pathSums[i] = grid[idx][col] + helper(idx+1, i, grid, dp);
    //     }
    //     auto count = min_element(pathSums.begin(), pathSums.end());
    //     return dp[idx][col] = (int)*count;
    // }

    vector<int> findMin(vector<int> vec)
    {
        int min1 = 1e9;
        int min2 = 1e9;
        int min1_idx = -1;
        for(int i = 0; i<vec.size(); i++)
        {
            if(vec[i]<min1)
            {
                min2 = min1;
                min1 = vec[i];
                min1_idx = i;
            }
            else if(vec[i]<min2)
            {
                min2 = vec[i];
            }
        }
        return {min1, min1_idx, min2};
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<int> next(n, 0);
        vector<int> curr(n, 0);
        for(int i = 0; i < grid.size(); i++)
        {
            next[i] = grid[n-1][i];
        }
        for(int idx = n-2; idx >=0; idx--)
        {
            vector<int> minVec = findMin(next);
            for(int col = 0; col < n ; col++)
            {
                int mini = 1e9;
                
                if(minVec[1] != col) mini = minVec[0];
                else mini = minVec[2];
                
                curr[col] = grid[idx][col] + mini;
            }
            next = curr;
        }

        auto it = min_element(next.begin(), next.end());
        int answer = *it;
        return answer;   
    }
};

// MISTAKES: WROTE GRID[IDX][COL] INSTEAD OF DP[IDX][COL]. TOTALLY STUPID.
// put next = curr inside the 2nd for loop
