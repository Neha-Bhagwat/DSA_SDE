class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        //brute force solution. first sort intervals
        for(int i = 0; i < intervals.size() - 1; i++)
        {
            for (int j = 0; j< intervals.size() - 1; j++)
            {
                if(intervals[j][0] > intervals[j+1][0])
                {
                    swap(intervals[j], intervals[j+1]);
                }
                else if (intervals[j][0] == intervals[j+1][0])
                {
                    if(intervals[j][1] > intervals[j+1][1])
                    {
                        swap(intervals[j], intervals[j+1]);
                    }
                }
            }
        }

        //or better, use the sort operator
        //then club intervals
        for(int i = 0; i < intervals.size()- 1; i++)
        {
           if(intervals[i][1] >= intervals[i+1][0])
           {
                intervals[i][1] = max(intervals[i][1],intervals[i+1][1]);
                intervals.erase(intervals.begin()+i+1);
                i--;
           } 
        }
        
        return intervals;
    }
};
