class Solution {
public:
    
    int MOD = 1e9+7;
    vector<int> dp=vector<int>(100001,-1);
    
    int helper(int ind, string &s){
        if(ind == s.size()){
            return 1;
        }
        
        if(s[ind] == '0'){
            return 0;
        }
        
        if(dp[ind] != -1){
            return dp[ind];
        }
        
        long long first = helper(ind+1, s);
		
        if(s[ind] == '*'){
            first = (first*9)%MOD;
        }
        
        long long second = 0;
        long long third = 0;
        
        if(ind+1 < s.size()){
            if(s[ind] == '1' || s[ind] == '*'){
                if(s[ind+1] == '*'){
                    second = helper(ind+2, s);
                    second = (second*9)%MOD;
                }
                else if(s[ind+1] != '*'){
                    second = helper(ind+2, s);
                }
            }
            if(s[ind] == '2' || s[ind] == '*'){
                if(s[ind+1] == '*') {
                    third = helper(ind+2, s);
                    third = (third*6)%MOD;
                }
                else if(s[ind+1]-'0' <= 6){
                    third = helper(ind+2, s);
                }
            }
        }
        
        return dp[ind] = ((first+second)%MOD+third)%MOD;
    }
    
    int numDecodings(string s) {
        
        return helper(0, s);
    }
};