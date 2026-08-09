class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea = 0, area;
        int i = 0, j = height.size()-1;
        while(j>i)
        {
            area = min(height[i], height[j]) * (j-i);
            maxArea = max(maxArea, area);

            if(height[j]> height[i]) i++;
            else j--;
        }
        return maxArea;
    }
};
