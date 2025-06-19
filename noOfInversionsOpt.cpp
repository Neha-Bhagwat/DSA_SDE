class Solution {
public:
    long long int noInversion = 0;
    void merge(vector<int> &arr, int low, int mid, int high)
    {
        int left = low;
        int right = mid+1;
        vector<int> temp;
        //here to merge array, we need to check between left and right indices
        while(left <= mid && right <=high)
        {
            //then if left is smaller, we add that
            if(arr[left] <= arr[right])
            {
                //add that element to temp
                temp.push_back(arr[left]);
                left++; //increment left ptr
            }
            else
            {
                temp.push_back(arr[right]);
                right++; //inc right ptr likewise
                noInversion+=(mid-left+1);
            }
        }
        //now, if one goes out of bounds
        while(left<=mid)
        {
            temp.push_back(arr[left]); //add to temp
            left++; //inc ptr
        }
        while(right <= high)
        {
            temp.push_back(arr[right]);
            right++; //inc ptr
        }
        //now, we will add this temp part properly to our og array
        for(int i = 0 ; i < high-low; i++)
        {
            //will begin from arr[low] and temp[0] 
            //will end with arr[high] and temp[high-low-1] 
            arr[low+i] = temp[i];
        }
        return;
    }
    void mergeSort(vector<int> &arr, int low, int high)
    {
        //base case
        if(low >=high)
        {
            return;
        }
        int mid = (low+high)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        merge(arr, low, mid, high);
    }

    long long int numberOfInversions(vector<int> nums) {
        long long int n = nums.size();
        //here we will use mergesort
        mergeSort(nums, 0, n-1);
        return noInversion;
    }
};
