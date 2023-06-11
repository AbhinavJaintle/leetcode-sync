class Solution {
public:
    int helper(int index, int prev, vector<vector<int>>& pairs, int curr, vector<vector<int>>& dp){
        if(index==pairs.size())return 0;
        int ans=0;
        if(dp[index][prev]!=-1)return dp[index][prev];
        if(pairs[index][0]>prev){
            ans=1+helper(index+1,pairs[index][1],pairs,curr+1,dp);
        }
        ans=max(ans,helper(index+1,prev,pairs,curr,dp));
        return dp[index][prev]=ans;
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        for(auto&i:pairs){
            i[0]+=1000;
            i[1]+=1000;
        }
        sort(pairs.begin(),pairs.end());
        vector<vector<int>> dp(pairs.size(),vector<int>(2001,-1));
        return helper(0,0,pairs,0,dp);
    }
};