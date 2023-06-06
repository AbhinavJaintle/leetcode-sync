class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        unordered_map<int,int> m;
        for(auto&i:spaces)m[i]++;
        string ans;
        for(int i = 0; i<s.length(); i++){
            if(m[i]){
                ans+=" ";
                m[i]=0;
                i--;
            }
            else{
                ans.push_back(s[i]);
            }
        }
        return ans;
    }
};