class Solution {
public:
    long long helper(int index, vector<int>& nums, map<pair<int,long long>,long long>&dp, long long curr){
        if(index==nums.size())return curr;
        if(dp[{index,curr}]!=0)return dp[{index,curr}];
        return dp[{index,curr}]=max(helper(index+1,nums,dp,curr*nums[index]),helper(index+1,nums,dp,curr));
    }
    long long maxStrength(vector<int>& nums) {
        map<pair<int,long long>,long long> dp;
        long long mini = LONG_MIN;
        for(int i = 0; i<nums.size(); i++){
            mini = max(mini,helper(i+1,nums,dp,nums[i]));
        }
        return mini;
    }
};