class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<pair<int,int>> v;
        for(int i = 0; i<costs.size(); i++){
            v.push_back({costs[i][0]-costs[i][1],i});
        }
        sort(v.begin(),v.end());
        int sum = 0;
        for(int i = 0; i<costs.size()/2; i++){
            sum+=costs[v[i].second][0];
        }
        for(int i = costs.size()/2; i<costs.size(); i++){
            sum+=costs[v[i].second][1];
        }
        return sum;
    }
};