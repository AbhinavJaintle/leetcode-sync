class Solution {
public:
    bool canConstruct(string s, int k) {
        unordered_map<char,int> m;
        for(auto&i:s){
            m[i]++;
        }
        int ans=0;
        for(auto&i:m){
            if(i.second%2!=0)ans++;
        }
        return k>=ans&&k<=s.length();
    }
};