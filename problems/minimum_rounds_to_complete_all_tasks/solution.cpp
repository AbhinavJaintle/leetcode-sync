class Solution {
public:
    int num(int curr,unordered_map<int,int>& dp){
        if(dp[curr]!=0){
            return dp[curr];
        }
        if(curr<0){
            return dp[curr]=1e+7;
        }
        if(curr==0){
            return dp[curr]=0;
        }
        if(curr%3==0){
            return dp[curr]=curr/3;
        }
        
        return dp[curr]=min(1+num(curr-3,dp),1+num(curr-2,dp));
        
    }
    int minimumRounds(vector<int>& tasks) {
        map<int,int> m;
        for(auto&i:tasks){
            m[i]++;
        }
        int ans = 0;
        unordered_map<int,int>dp;
        for(auto&i:m){
            int temp = num(i.second,dp);
            if(temp>1e+6){
                return -1;
            }
            ans+=temp;
        }
        return ans;
    }
};