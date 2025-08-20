//initial idea didnt work.

// class Data 
// {
//     public:
//     int departure;
//     int arrival;
// };

class Solution 
{
  public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(vector<int>& arr, vector<int>& dep) 
    {
        int count = 0;
        int n = dep.size();
        
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        
        int arrPtr = 0, depPtr = 0, maxCount = 0;
        
        while(arrPtr < n && depPtr < n)
        {
            if(arr[arrPtr]<=dep[depPtr])
            {
                count++;
                arrPtr++;
            }
            else
            {
                count--;
                depPtr++;
            }
            
            maxCount = max(maxCount, count);
        }
        
        while(arrPtr<n)
        {
            count++;
            arrPtr++;
            maxCount = max(maxCount, count);   
        }
        
        return maxCount;
    }
};

        //sort accd to departure
        // vector<Data> vec(n);
        // for(int i = 0; i< n; i++)
        // {
        //     vec[i].departure = dep[i];
        //     vec[i].arrival = arr[i];
        // }
        
        // //vector of data type is populated, now we sort it lexicographically
        
        // sort(vec.begin(), vec.end(), [](const Data& d1, const Data& d2)
        // {
        //     if(d1.departure == d2.departure)
        //     {
        //         return d1.arrival<d2.arrival;
        //     }
        //     else
        //     {
        //         return d1.departure<d2.departure;
        //     }
        // });
        
        // for(int i = 0; i< n; i++)
        // {
        //     cout<<vec[i].arrival<<" "<<vec[i].departure<<endl;
        // }
        
        // vector<int> lastDeparture(n,-1);
        // // lastDeparture.push_back(-1);
        
        // for(int i = 0; i< n; i++)
        // {
        //     int j;
        //     for(j = 0; (j < n && lastDeparture[j] != -1) ; j++)
        //     {
        //         if(lastDeparture[j] < vec[i].arrival)
        //         {
        //             lastDeparture[j] = vec[i].departure;
        //             break;
        //         }
        //     }
        //     //if that doesnt work out and it doesnt continue, then..
        //     if(j >= n || lastDeparture[j] == -1)
        //     {
        //         count++;
        //         lastDeparture[count-1] = vec[i].departure;
        //     }
        // }
