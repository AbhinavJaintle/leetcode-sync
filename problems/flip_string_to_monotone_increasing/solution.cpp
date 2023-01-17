class Solution {
public:
    int minFlipsMonoIncr(string s) {
        vector<pair<int,int>> v;
        pair<int,int> prev={0,0};
        for(auto&i:s){
            prev.first=i=='0'?prev.first+1:prev.first;
            prev.second=i=='1'?prev.second+1:prev.second;
            v.push_back(prev);
        }
        int mini=min(v[s.length()-1].first,v[s.length()-1].second);
        for(int i = 0; i<s.length(); i++){
            mini=min(mini,v[i].second+v[s.length()-1].first-v[i].first);
        }
        return mini;
    }
};