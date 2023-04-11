class Solution {
public:
    bool judgeCircle(string moves) {
        unordered_map<char,int> m;
        for(auto&i:moves){
            m[i]++;
        }
        return m['D']==m['U']&&m['R']==m['L'];
    }
};