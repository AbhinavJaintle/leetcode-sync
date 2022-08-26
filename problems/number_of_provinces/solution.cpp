class Solution {
public:
    void dfs(int index, vector<int>& vis, vector<vector<int>> adj){
        vis[index]=1;
        for(auto& i: adj[index]){
            if(vis[i]!=1){
                dfs(i,vis,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<vector<int>> adj(isConnected[0].size());
        for(int i = 0; i<isConnected.size(); i++){
            for(int j = 0;  j<isConnected[i].size(); j++){
                if(i!=j&&isConnected[i][j]==1) adj[i].push_back(j), adj[j].push_back(i);
            }
        }
        vector<int> vis(isConnected[0].size(),0);
        int count= 0;
        for(int i = 0; i<isConnected[0].size(); i++){
            if(vis[i]!=1){
                count++;
                dfs(i,vis,adj);
            }
        }
        return count;
    }
};