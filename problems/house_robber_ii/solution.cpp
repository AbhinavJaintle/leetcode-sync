class Solution {
public:
    int rob(vector<int>& nums) {
        int n = size(nums);
        return n == 1 ? nums[0] : max(rob1(nums, 0, n-2), rob1(nums, 1, n-1));
    }
    
    int rob1(vector<int>& nums, int l, int r) {
        int dp[2] = {};
        for (int i = l; i <= r; i++)
            dp[i%2] = max(dp[(i+1)%2], dp[i%2] + nums[i]);
        return dp[(r+2)%2];
    }
};