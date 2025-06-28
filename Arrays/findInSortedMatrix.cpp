//binary search both arrays for the best time complexity
// one more thing that can be done is write the 2d array as a 1d array and then do binary search. but space complexity becomes O[n*m]
//we use certain mathematical understandings to go forward with this

class Solution {
public:
    bool binarySearch(vector<vector<int>>& matrix, int low, int high, int target)
    {
        //base case
        if(low > high)
        {
            return false;
        }
        int mid = (low + high)/2;
        int m = matrix[0].size();
        
        if(matrix[mid/m][mid%m] == target)
        {
            return true;
        }
        else
        {
            if(matrix[mid/m][mid%m] > target)
            {
                //then check behind
                return binarySearch(matrix, low, mid - 1, target);
            }
            else
            {
                return binarySearch(matrix, mid + 1, high, target); //search ahead
            }
        }
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        //s1. mid, high and low
        int low = 0;
        int high = (matrix.size()*matrix[0].size()) - 1; //here, high is m*n-1
        return binarySearch(matrix, low, high, target);
    }

//this is the better solution using only one function and sorting it out there
    bool searchMatrixBetter(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int low = 0;
        int high = n * m - 1;
        while(low<=high){
            int mid = (low+high)/2;
            int x = mid/m;
            int y = mid%m;
            if(matrix[x][y] == target){
                return true;
            }
            else if(matrix[x][y] > target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }

        }
        return false;
    }
};

