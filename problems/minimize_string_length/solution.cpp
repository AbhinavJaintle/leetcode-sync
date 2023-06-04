class Solution {
public:
    int minimizedStringLength(string s) {
        unordered_map<int,int> m;
        int count=0;
        for(auto&i:s){
            if(!m[i])count++;
            m[i]++;
        }
        return count;
    }
};