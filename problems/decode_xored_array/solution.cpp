class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        vector<int> ans = {first};
        for(auto&i:encoded){
            ans.push_back(i^ans[ans.size()-1]);
        }
        return ans;
    }
};