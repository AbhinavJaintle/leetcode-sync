class Solution {
public:
    int helper(int index, vector<int>& days, vector<int>& costs, unordered_map<int,int>& dp){
        if(index==days.size())return 0;
        if(dp[index])return dp[index];
        int ops1=0;
        int ops2=0;
        int ops3=0;
        int curr=days[index];
        ops1=costs[0]+helper(index+1,days,costs,dp);
        int temp=index+1;
        curr+=6;
        while(temp<days.size()&&days[temp]<=curr){
            temp++;
        }
        curr-=6;
        ops2=costs[1]+helper(temp,days,costs,dp);
        curr+=29;
        temp=index+1;
        while(temp<days.size()&&days[temp]<=curr){
            temp++;
        }
        ops3=costs[2]+helper(temp,days,costs,dp);
        return dp[index]=min({ops1,ops2,ops3});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        unordered_map<int,int> dp;
        return helper(0,days,costs,dp);
    }
};