class Solution {
    unordered_map<int,int> dp;
public:
    int helper(long long n){
        if(n==1)return 0;
        if(dp[n])dp[n];
        int ans=1;
        if(n%2==0)ans+=helper(n/2);
        else{
            ans+=min(helper(n-1),helper(n+1));
        }
        return dp[n]=ans;
    }
    int integerReplacement(int n) {
        return helper(n);
    }
};