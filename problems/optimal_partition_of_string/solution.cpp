class Solution {
public:
    int partitionString(string s) {
        unordered_map<char,int> m;
        int sum=1;
        for(auto&i:s){
            if(m[i]){
                sum++;
                m.clear();
            }
            m[i]++;
        }
        return sum;
    }
};