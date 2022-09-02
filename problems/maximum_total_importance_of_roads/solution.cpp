class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n,vector<int>{});
        for(auto&i:roads){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<long long int> temp;
        for(auto&i:adj){
            temp.push_back(i.size());
        }
        sort(temp.begin(),temp.end());
        long long int count=0;
        for(int i = n; i>0; i--){
            count+=temp[i-1]*i;
        }
        return count;
    }
};