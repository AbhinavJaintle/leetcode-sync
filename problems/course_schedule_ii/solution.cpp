class Solution {
public:
    bool dfs(int index, vector<vector<int>>& adj, vector<int>& vis, map<int,int>& m, vector<int>& ans){
        if(m[index]==1){
            return true;
        }
        if(vis[index]==1){
            return false;
        }
        vis[index]=1;
        for(auto&i:adj[index]){
            if(!dfs(i,adj,vis,m,ans)){
                return false;
            }
        }
        ans.push_back(index);
        m[index]=1;
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>vis(numCourses,0);
        vector<vector<int>> adj(numCourses,vector<int>{});
        vector<int> ans;
        map<int,int> m;
        for(auto&i:prerequisites){
            adj[i[0]].push_back(i[1]);
        }
        for(int i = 0; i<adj.size(); i++){
            if(adj[i].size()==0){
                m[i]=1;
                ans.push_back(i);
            }
        }
        for(int i = 0; i<numCourses; i++){
            if(m[i]!=1){
                if(!dfs(i,adj,vis,m,ans)){
                    return {};
                }
            }
        }
        return ans;
    }
};