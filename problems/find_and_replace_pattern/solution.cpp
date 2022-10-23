class Solution {
public:
    string patternise(string s){
        unordered_map<char,int> m;
        string temp;
        int count = 10;
        for(auto&i:s){
            if(m[i]==0){
                count++;
                m[i]=count;
            }
            temp+=to_string(m[i]);
        }
        return temp;
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        string target = patternise(pattern);
        vector<string> ans;
        for(auto&i:words){
            if(patternise(i)==target){
                ans.emplace_back(i);
            }
        }
        return ans;
    }
};