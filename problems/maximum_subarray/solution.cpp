class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = nums[0], curr = 0, i=0;
        for (int i=0; i<nums.size(); i++){
            curr+=nums[i];
            maxSum = max(curr, maxSum);
            curr = max(curr, 0);
        }
        return maxSum;
    }
};