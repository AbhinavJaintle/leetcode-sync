class Solution {
public:

vector<vector<int>>dp;


int maxProfit(vector<int>& nums) {
    
    int n=nums.size();
    dp.resize(nums.size()+1,vector<int>(2,0));
    
    dp[n][0]=dp[n][1]=0;
    
    for(int ind=n-1;ind>=0;ind--)
    {
        for(int buy=0;buy<=1;buy++)
        {
            int profit=0;
            if(buy)
            {
                profit=max(-nums[ind]+dp[ind+1][0],dp[ind+1][1]);
            }
            else
            {
                profit=max(nums[ind]+dp[ind+1][1],dp[ind+1][0]);
            }
            dp[ind][buy]= profit;
        }
    }
    
    return dp[0][1];
    
}

};