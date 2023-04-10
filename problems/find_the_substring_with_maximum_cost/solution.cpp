class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int> v(26,-1001);
        for(int i = 0; i<chars.length(); i++){
            v[chars[i]-'a']=vals[i];
        }
        int maxi=0;
        int curr=0;
        for(int i = 0; i<s.length(); i++){
            if(v[s[i]-'a']!=-1001)curr+=v[s[i]-'a'];
            else curr+=s[i]-'a'+1;
            if(curr<0)curr=0;
            maxi=max(maxi,curr);
        }
        return maxi;
    }
};