class Solution {
public:
    int helper(int index, vector<int>& stoneValue, char ch, vector<vector<int>>& dp){
        if(index==stoneValue.size())return 0;
        if(dp[index][ch-'A']!=-1)return dp[index][ch-'A'];
        int ans;
        if(ch=='A'){
            ans=-1*INT_MAX;
            int prev=0;
            for(int i = index; i<min((int)stoneValue.size(),index+3); i++){
                prev+=stoneValue[i];
                ans=max(ans,prev+helper(i+1,stoneValue,'B',dp));
            }
        }
        else{
            ans=INT_MAX;
            for(int i = index; i<min((int)stoneValue.size(),index+3); i++){
                ans=min(ans,helper(i+1,stoneValue,'A',dp));
            }
        }
        return dp[index][ch-'A'] = ans;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        vector<vector<int>> dp(stoneValue.size(),vector<int>(2,-1));
        int a = helper(0,stoneValue, 'A', dp);
        int b = accumulate(stoneValue.begin(),stoneValue.end(),0)-a;
        if(a==b)return "Tie";
        return a>b?"Alice":"Bob";
    }
};