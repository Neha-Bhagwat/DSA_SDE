//recursion + memoization
//Geek is going for a training program for n days. He can perform any of these activities: Running, Fighting, and Learning Practice. Each activity has some point on each day. As Geek wants to improve all his skills, he can't do the same activity on two consecutive days. Given a 2D array arr[][] of size n where arr[i][0], arr[i][1], and arr[i][2] represent the merit points for Running, Fighting, and Learning on the i-th day, determine the maximum total merit points Geek can achieve.
//Input: arr[]= [[1, 2, 5], [3, 1, 1], [3, 3, 3]]
//Output: 11
//Explanation: Geek will learn a new move and earn 5 point then on second day he will do running and earn 3 point and on third day he will do fighting and earn 3 points so, maximum merit point will be 11. 
class Solution {
  public:
    int pointRecur(int day, int last, vector<vector<int>>& arr,  vector<vector<int>>& dp)
    {
        //base case
        int maxi = 0;
        if(day == 0)
        {
            for(int i = 0 ; i <=2 ; i++)
            {
                if(last!=i)
                {
                    maxi = max(maxi, arr[0][i]);
                }
                
            }
            return maxi;
        }
        
        int points;
        //normal case
        for(int i = 0; i <=2; i++)
        {
            if(last!=i)
            {
                if(dp[day-1][i] != -1) return dp[day-1][i];
                else points = arr[day][i] + pointRecur(day-1, i, arr, dp); //gives the previous tree ka max points score
                maxi = max(points,maxi);
            }
        }
        
        return dp[day][last] = maxi;
    }
    int maximumPoints(vector<vector<int>>& arr) {
        vector<int> temp(3,-1);
        vector<vector<int>> dp(arr.size(), temp);
        return pointRecur(arr.size()-1, 3, arr, dp);
    }
};
