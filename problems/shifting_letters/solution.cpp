class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        s[shifts.size()-1]='a'+(s[shifts.size()-1]-'a'+shifts[shifts.size()-1])%26;
        for(int i = shifts.size()-2; i>=0; i--){
            shifts[i] = (shifts[i]%26+shifts[i+1]%26)%26;
            s[i]='a'+(s[i]-'a'+shifts[i])%26;
        }
        return s;
    }
};