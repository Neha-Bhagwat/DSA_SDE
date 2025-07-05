//draw recursive tree, it helps a lott
//logic is find all subsets by 2 options, either select or dont select.
//then, sum is returned after we do this for all the elements 

class Solution{   
public:
    void subsetSum(vector<int> &arr, int idx, int sum, vector<int> &ans){
        //recursion base condition is that sum=0, index from beginning
        int n = arr.size();
        if(idx==n) 
        {
            ans.push_back(sum);
        }
        //case where we take the element
        subsetSum(arr, idx+1, sum+arr[idx], ans);
        //case where we dont take the element
        subsetSum(arr, idx+1, sum, ans);
    }

    vector<int> findSum(vector<int>arr)
    {
        //here, we call the recursive function subsetSum
        int sum = 0;
        int idx = 0;
        vector<int> answer;
        subsetSum(arr,idx,sum,answer);
        sort(answer.begin(), answer.end());
        return answer;
    }
};
