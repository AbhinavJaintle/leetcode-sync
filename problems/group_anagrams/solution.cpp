class Solution {
public:
    map <string, vector<string>> m;
    map <string, vector<string>> :: iterator itr;
    vector<vector<string>> ans;
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        for(int i = 0; i<strs.size(); i++){
             string temp = strs[i];
             sort(temp.begin(), temp.end());
             m[temp].push_back(strs[i]);
        }
        for(itr = m.begin(); itr!=m.end(); ++itr){
            ans.push_back(itr->second);
        }
       return ans;
    }
};