class Solution {
public:
    string makeGood(string s) {
        for(int i = 1; i<s.length(); i++){
            if((s[i]<92&&s[i-1]==s[i]+32)||(s[i]>92&&s[i-1]==s[i]-32)){
                s.erase(i-1,2);
                return makeGood(s);
            }
        }
        return s;
    }
};