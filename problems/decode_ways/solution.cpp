class Solution {
public:
    int decode(int index, string s, unordered_map<string,int>& m,vector<int>& dp){
        if(index==s.length()){
            return 1;
        }
        if(dp[index]!=-1){
            return dp[index];
        }
        string one;
        one.push_back(s[index]);
        string two;
        if(index<s.length()-1){
            two = one;
            two.push_back(s[index+1]);
        }
        int ans = 0;
        if(m[one]!=0){
            ans += decode(index+1,s,m,dp);
        }
        if(two!=""&&m[two]!=0){
            ans+=decode(index+2,s,m,dp);
        }
        return dp[index]=ans;
    }
    int numDecodings(string s) {
        unordered_map<string,int> m;
        for(int i = 1; i<27; i++){
            m[to_string(i)]=1;
        }
        vector<int> dp(s.length(),-1);
        return decode(0,s,m,dp);
    }
};