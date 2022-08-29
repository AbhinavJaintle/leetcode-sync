class Solution {
public:
    void dfs(vector<vector<int>>& adj,int index, vector<int>& vis){
        if(adj[index].size()==0){
            vis[index]=1;
            return;
        }
        vis[index]=1;
        
        for(auto&i:adj[index]){
            if(vis[i]==0){
                dfs(adj,i,vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n,vector<int>{});
        for(auto&i:connections){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int> vis(n,0);
        int ret = -1;
        for(int i = 0; i<n; i++){
            if(vis[i]==0){
                ret++;
                dfs(adj,i,vis);
            }
        }
        int curr=0;
        for(auto&i:adj){
            if(adj.size()!=0){
                curr++;
            }
        }
        if(connections.size()<n-1){
            return -1;
        }
        return ret;
    }
};