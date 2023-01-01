class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> m;
        unordered_map<string, int> vis;
        vector<string> v;
        string temp;
        stringstream iss(s);
        while(iss>>temp){
            v.push_back(temp);
        }
        if(pattern.length()!=v.size()){
            return false;
        }
        for(int i = 0; i<pattern.length(); i++){
            if(m[pattern[i]]!=""){
                if(m[pattern[i]]!=v[i]){
                    return false;
                }
            }
            else{
                if(vis[v[i]]){
                    return false;
                }
                m[pattern[i]]=v[i];
                vis[v[i]]++;
            }
        }
        return true;
    }
};