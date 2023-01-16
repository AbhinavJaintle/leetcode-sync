class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> m;
        for(auto&i:arr) m[i]++;
        for(auto&i:target) m[i]--;
        for(auto&i:m){
            if(i.second!=0) return false;
        }
        return true;
    }
};