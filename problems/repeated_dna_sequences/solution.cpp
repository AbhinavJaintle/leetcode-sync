class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string, int> m;
        vector<string> ans;
        if(s.length()<10){
            return {};
        }
        for(int i = 0; i<s.size()-9; i++){
            m[s.substr(i,10)]+=1;
        }
        for(auto i: m){
            if(i.second>1){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};