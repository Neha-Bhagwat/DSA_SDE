//973. K Closest Points to Origin

// Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).

// The distance between two points on the X-Y plane is the Euclidean distance (i.e., √(x1 - x2)2 + (y1 - y2)2).

// You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).

//Example 1
// Input: points = [[1,3],[-2,2]], k = 1
// Output: [[-2,2]]
// Explanation:
// The distance between (1, 3) and the origin is sqrt(10).
// The distance between (-2, 2) and the origin is sqrt(8).
// Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
// We only want the closest k = 1 points from the origin, so the answer is just [[-2,2]].

//custom comparator
struct MyComparator{
    bool operator() (const vector<int> &tuple1, const vector<int>& tuple2)
    {
        int dist1 = tuple1[0]*tuple1[0] + tuple1[1]*tuple1[1];
        int dist2 = tuple2[0]*tuple2[0] + tuple2[1]*tuple2[1];
        return dist1>dist2;
        //true means 1 has lesser priority than 2. false means 1 has greater priority than 2.
    }

};


//solution
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) 
    {
        priority_queue<
            vector<int>, 
            vector<vector<int>>, 
            MyComparator> pq(points.begin(), points.end());
        vector<vector<int>> ans;

        for(int i = 0; i<k;i++)
        {
            ans.push_back(pq.top());
            pq.pop();
        }
        return ans;
        // return points;
    }
};
