class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> m(26,0);
        for(auto&i:p)m[i-'a']++;
        vector<int> m1(26,0);
        int curr=0;
        int prev=0;
        vector<int> v;
        for(int i = 0; i<s.length(); i++){
            m1[s[i]-'a']++;
            curr++;
            if(curr>p.length()){
                m1[s[prev]-'a']--;
                prev++;
                if(m1==m)v.push_back(prev);
            }
            else{
                if(m1==m)v.push_back(prev);
            }
        }
        return v;
    }
};