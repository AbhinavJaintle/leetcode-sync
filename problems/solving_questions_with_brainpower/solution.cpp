class Solution {
public:
    long long helper(int index, vector<vector<int>>& question, vector<long long>& dp){
        if(index>=question.size())return 0;
        if(dp[index]!=-1)return dp[index];
        return dp[index] = max(question[index][0]+helper(index+question[index][1]+1,question,dp),helper(index+1,question,dp));
    }
    long long mostPoints(vector<vector<int>>& question) {
        vector<long long> dp(question.size(),-1);
        return helper(0,question,dp);
    }
};