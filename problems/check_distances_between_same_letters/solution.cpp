class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        map<char,int> m;
        if(distance[s[0]-97]+1<s.length()&&s[distance[s[0]-97]+1]==s[0]){
            m[s[0]] = distance[s[0]-97]+1;
        }
        else{
            return false;
        }
        for(int i = 1; i<s.length(); i++){
            if(m[s[i]]==i){
                continue;
            }
            else if(m[s[i]]!=0){
                return false;
            }
            else if(i+distance[s[i]-97]+1<s.length()&&s[i+distance[s[i]-97]+1]==s[i]){
                m[s[i]] = i+distance[s[i]-97]+1;
            }
            else{
                return false;
            }
        }
        return true;
    }
};