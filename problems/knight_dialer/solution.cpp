class Solution {
int mod = 1e9+7;
map<pair<int,int>,int> dp;
public:
    int helper(int n, int curr, vector<vector<int>>& adj){
        if(n==0)return 1;
        if(dp[{n,curr}])return dp[{n,curr}];
        int sum=0;
        for(auto&i:adj[curr]){
            sum=(sum+helper(n-1,i,adj)%mod)%mod;
        }
        return dp[{n,curr}]=sum%mod;
    }
    int knightDialer(int n) {
        vector<vector<int>> adj = {{4,6},{6,8},{7,9},{8,4},{3,9,0},{},{1,7,0},{2,6},{1,3},{4,2}};
        int sum=0;
        for(int i = 0; i<=9; i++){
            sum=(sum+helper(n-1,i,adj))%mod;
        }
        return sum;
    }
};