class Solution {
public:
    int helper(int index, vector<int>& nums1, vector<int>& nums2, int left, vector<vector<int>>& dp){
        if(index==nums1.size())return 0;
        int t = -1;
        if(dp[index][left]!=-1)return dp[index][left];
        for(int i = left; i<nums2.size(); i++){
            if(nums2[i]==nums1[index]){
                t=i;
                break;
            }
        }
        int ops1=0,ops2=0;
        if(t!=-1){
            ops1=1+helper(index+1,nums1,nums2,t+1,dp);
        }
        ops2=helper(index+1, nums1,nums2,left,dp);
        return dp[index][left]=max(ops1,ops2);
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(),vector<int>(nums2.size()+1,-1));
        return helper(0,nums1,nums2,0,dp);
    }
};