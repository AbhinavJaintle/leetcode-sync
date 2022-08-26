class Solution {
public:
    // A safe node will not be a part of a cycle 
// Checks in hashmap about cycle
 bool dfs(int i,vector<vector<int>> &graph,map<int,bool> &mp) { 
        if(mp.find(i)!=mp.end()){
            return mp[i];
        }
        mp[i]=false;
        for(auto it:graph[i]){
            if(!dfs(it,graph,mp)){
                return mp[i];
            }
        }
        mp[i]=true;
        return mp[i];
        
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        map<int,bool> mp;
        vector<int> ans;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(dfs(i,graph,mp)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};