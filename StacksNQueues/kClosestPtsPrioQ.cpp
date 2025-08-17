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
