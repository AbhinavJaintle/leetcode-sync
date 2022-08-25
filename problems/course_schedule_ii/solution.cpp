class Solution {
public:
    bool dfs(int index, vector<vector<int>>& adj, vector<int>& vis,vector<int>& ans,vector<int>& ret,map<int,int>& m){
        if(m[index]==1){
            return true;
        }
        if(vis[index]==1){
            m[index]=1;
            ans.push_back(index);
            return true;
        }
        if(ret[index]==1){
            return false;
        }
        ret[index]=1;
        for(auto& i: adj[index]){
            if(dfs(i,adj,vis,ans,ret,m)==false) return false;
        }
        vis[index]=1;
        m[index]=1;
        ans.push_back(index);
        return true;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> ans;
        map<int,int> m;
        for(auto& i: prerequisites){
            adj[i[0]].push_back(i[1]);
        }
        vector<int> vis(numCourses);
        vector<int> ret(numCourses);
        for(auto& i: prerequisites){
            if(vis[i[0]]==0){
                if(!dfs(i[0],adj,vis,ans,ret,m)) return {};
            }
        }
        for(int i = 0; i<numCourses; i++){
            if(!m[i]) ans.push_back(i);
        }
        return ans;
    }
};