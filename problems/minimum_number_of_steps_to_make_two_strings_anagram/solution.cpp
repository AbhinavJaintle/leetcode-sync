class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int>m;
        for(auto&i:s){
            m[i]++;
        }
        for(auto&i:t){
            if(m[i]!=0){
                m[i]--;
            }
        }
        int steps = 0;
        for(auto&i:m){
            if(i.second!=0){
                steps+=i.second;
            }
        }
        return steps;
    }
};