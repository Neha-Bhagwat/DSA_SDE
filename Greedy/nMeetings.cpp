//Logic: here, we have a scheduling situation. with the data structure Data, we can store everything we want and need inside a vector and even return what number of tasks are performed. We use a custom comparator to sort according to end times, because accd to greedy, we want to do the tasks that need the shortest time. Other algorithms would take mre time.

class Data {
  public:
    int start;
    int end;
    int pos;
};

class Solution {
  public:
    
    
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) 
    {
        //Maximum time complexity we can get is nlogn.
        int n = start.size(), count = 0;
        //populating the data structure
        //using custom comparator to sort the ds
        vector<Data> arr(n);
        for(int i = 0; i< n; i++)
        {
            arr[i].start = start[i];
            arr[i].end = end[i];
            arr[i].pos = i+1;
        }
      //sort custom comparator with lambda function. IMP!!
        sort(arr.begin(), arr.end(), [](const Data& d1, const  Data& d2) 
        {
            if(d1.end == d2.end)
            {
                if(d1.start == d2.start)
                {
                    return d1.pos<d2.pos;   
                }
                else return d1.start<d2.start;
            }
            else return d1.end<d2.end;
        });
        int lastMeetingEnd = -1;
        //now logic of the code:
        //inc count if it is possible to accomodate meetings
        // for(int i = 0; i<n ; i++)
        // {
        //     cout<<arr[i].start<<" "<<arr[i].end<<" "<<arr[i].pos<<endl;    
        // }
        
        for(int i = 0; i<n; i++)
        {
            if(lastMeetingEnd<arr[i].start)
            {
                count++;
                lastMeetingEnd = arr[i].end;
            }
        }
        
        return count;
    }
};
