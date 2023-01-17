class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> m;
        for(auto&i:s){
            m[i]++;
        }
        string ans;
        for(auto&i:order){
            if(m[i]){
                while(m[i]){
                    ans.push_back(i);
                    m[i]--;
                }
            }
        }
        for(auto&i:m){
            if(i.second!=0){
                while(i.second){
                    ans.push_back(i.first);
                    i.second--;
                }
            }
        }
        return ans;
    }
};