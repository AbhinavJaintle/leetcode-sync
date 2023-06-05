class Solution {
public:
    int helper(int index, vector<vector<int>>& adj, unordered_map<int,int>& vis, unordered_map<int,int>& res){
        int ans = 1;
        vis[index]++;
        for(auto&i:adj[index]){
            if(!vis[i]&&!res[i])ans+=helper(i,adj,vis,res);
        }
        return ans;
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        vector<vector<int>> adj(n);
        unordered_map<int,int> vis;
        unordered_map<int,int> res;
        for(auto&i:restricted)res[i]++;
        for(auto&i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        return helper(0,adj,vis,res);
    }
};