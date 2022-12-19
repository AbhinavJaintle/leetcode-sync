class Solution {
public:
    int countGoodSubstrings(string s) {
        unordered_map<char,int> m;
        if(s.length()<3){
            return 0;
        }
        int start = 0;
        m[s[0]]++;
        m[s[1]]++;
        m[s[2]]++;
        int count = 0;
        if(m.size()==3){
            count++;
        }
        for(int i = 3; i<s.length(); i++){
            m[s[start]]--;
            if(m[s[start]]==0){
                m.erase(s[start]);
            }
            start++;
            m[s[i]]++;
            if(m.size()==3){
                count++;
            }
        }
        return count;
    }
};