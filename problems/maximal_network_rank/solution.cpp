class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n,vector<int>{});
        for(auto&i:roads){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        int ans = 0;
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                int temp1 = adj[i].size();
                int temp2 = adj[j].size();
                int count = 1;
                if(find(adj[i].begin(),adj[i].end(),j)==adj[i].end()){
                    count=0;
                }
                ans = max(ans,temp1+temp2-count);       
            }
        }
        return ans;
    }
};