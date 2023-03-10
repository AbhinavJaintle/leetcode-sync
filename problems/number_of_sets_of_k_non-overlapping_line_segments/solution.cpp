class Solution {
public:
    long int mod=1e9+7;
    int dp[1001][1001][2];
    long int solve(int r,int n,int num,bool start)
    {   
            if(r>=n) return 0;
        if(num==0)return 1;
        int ans=0;
        if(dp[r][num][start]!=-1) return dp[r][num][start];
        
        if(start)
        {
            ans+=solve(r,n,num,0);ans=ans%mod;//start it
            ans+=solve(r+1,n,num,1);ans=ans%mod;//postpone it
        }
        
        else
        {
            ans+=solve(r+1,n,num-1,1);ans=ans%mod;//end it 
            ans+=solve(r+1,n,num,0);ans=ans%mod;//extend it
        }
        
        return dp[r][num][start]=ans%mod;
        
    }
    int numberOfSets(int n, int k) {
        memset(dp,-1,sizeof(dp));
        
        return solve(0,n,k,1);
    }
};