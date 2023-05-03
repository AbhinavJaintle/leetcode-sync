class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& n1, vector<int>& n2) {
        sort(n1.begin(),n1.end());
        sort(n2.begin(),n2.end());
        auto ip = unique(n1.begin(),n1.end());
        n1.resize(distance(n1.begin(),ip));
        ip = unique(n2.begin(),n2.end());
        n2.resize(distance(n2.begin(),ip));
        unordered_map<int,int> m1, m2;
        for(auto&i:n1)m1[i]++;
        for(auto&i:n2)m2[i]++;
        vector<vector<int>> ans(2);
        for(auto&i:n1){
            if(!m2[i])ans[0].push_back(i);
        }
        for(auto&i:n2){
            if(!m1[i])ans[1].push_back(i);
        }
        return ans;
    }
};