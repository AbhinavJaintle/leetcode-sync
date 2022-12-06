class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        unordered_map<char,int> m;
        char prev = s[0];
        m[prev]++;
        int temp = 0;
        for(int i = 1; i<s.length(); i++){
            if(s[i]==prev){
                m[prev]++;
            }
            else{
                if(m[prev]>=3){
                    ans.push_back({temp,i-1});
                }
                m[prev]=0;
                temp = i;
                prev = s[i];
                m[prev] += 1;
            }
        }
        int n = s.length();
        if(m[prev]>=3){
            ans.push_back({temp,n-1});
            m[prev]=0;
        }
        return ans;
    }
};