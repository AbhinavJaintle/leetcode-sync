class Solution {
public:
    int helper(int index, vector<int>& piles, vector<vector<vector<int>>>& dp, char ch, int m){
        if(index==piles.size())return 0;
        if(dp[index][m][ch-'A']!=-1)return dp[index][m][ch-'A'];
        int ans = 0;
        if(ch=='A'){
            ch='B';
            int prev=0;
            for(int i = index; i<min((int)piles.size(),index+2*m); i++){
                prev+=piles[i];
                ans=max(ans,prev+helper(i+1,piles,dp,ch,max(i+1-index,m)));
            }
            ch='A';
        }
        else{
            ch='A';
            ans=INT_MAX;
            for(int i = index; i<min((int)piles.size(),index+2*m); i++){
                ans=min(ans,helper(i+1,piles,dp,ch,max(i+1-index,m)));
            }
            ch='B';
        }
        return dp[index][m][ch-'A'] = ans;
    }
    int stoneGameII(vector<int>& piles) {
        vector<vector<vector<int>>> dp(piles.size(),vector<vector<int>>(2*piles.size()+1,vector<int>(2,-1)));
        return helper(0,piles,dp,'A',1);
    }
};