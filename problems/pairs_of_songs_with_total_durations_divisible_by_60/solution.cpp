class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int> m;
        int sum=0;
        for(auto&i:time){
            for(auto&j:m){
                if((i+j.first)%60==0) sum+=j.second;
            }
            m[i]++;
        }
        return sum;
    }
};