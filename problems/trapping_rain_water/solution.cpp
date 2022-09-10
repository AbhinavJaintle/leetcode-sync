class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size()==0) return 0; 
        int left = 0, right = height.size()-1; 
        int leftMax=0, rightMax=0; 
        int ans = 0; 
        while (left < right) {
            if (height[left] > leftMax) leftMax = height[left]; 
            if (height[right] > rightMax) rightMax = height[right];
            if (leftMax < rightMax) {
                ans += leftMax-height[left]; 
                left++; 
            } else {
                ans += rightMax-height[right]; 
                right--; 
            }
        }
        return ans; 
    }
};