class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        vector<int> v(s.length());
        for(int i = 1; i<s.length(); i++){
            if(s[i]==s[i-1])v[i]=v[i-1]+1;
            else v[i]=v[i-1];
        }
        int maxi=1;
        for(int i = 0; i<s.length(); i++){
            for(int j = i+1; j<s.length(); j++){
                if(v[j]-v[i]<=1)maxi=max(maxi,j-i+1);
                else break;
            }
        }
        return maxi;
    }
};