class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //they point to last element
        int ptr1 = m - 1;
        int ptr2 = n - 1;
        for(int i = m + n - 1; i >= 0; i--)
        {
            if(ptr2 < 0)
            {
                //in the case that num2 has no more elements, nums1 is done
                break;
            }
            if(ptr1 < 0)
            {
                //rest of the elements of nums2 need to be there, so we add them this way
                nums1[i] = nums2[ptr2];
                ptr2--;
            }
            //if second is greater than 1st, add it to the end
            else if(nums1[ptr1] < nums2[ptr2])
            {
                //then add nums2 element to the end, dec ptr2
                nums1[i] = nums2[ptr2];
                ptr2--;
            }
            else
            {
                //if not, same thing wiht nums1 element
                nums1[i] = nums1[ptr1];
                ptr1--;
            }
        }
    }
};
