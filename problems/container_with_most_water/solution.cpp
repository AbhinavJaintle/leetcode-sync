class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left=0, right=n-1;
        int maxwater = 0;
        
        while(left<=right){
            if(height[left]<=height[right]){
                maxwater = max( maxwater, min(height[left],height[right])*(right-left) );
                left++;
            }          
            else{
                maxwater = max( maxwater, min(height[left],height[right])*(right-left) );
                right--;
            }   
        }
        
        return maxwater;        
    }
};