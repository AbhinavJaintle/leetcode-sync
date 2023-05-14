class Solution {
public:
    int helper(int index, vector<vector<int>>& adj, unordered_map<int,int>& m, int& prev){
        m[index]++;
        int sz=adj[index].size();
        if(sz!=prev){
            prev=min(prev,sz);
        }
        int ans=0;
        for(auto&i:adj[index]){
            if(!m[i]){
                ans+=1+helper(i,adj,m,prev);
            }
        }
        return ans;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto&i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        unordered_map<int,int> vis;
        int count=0;
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                int prev=adj[i].size();
                int val=helper(i,adj,vis,prev);
                if(val==prev)count++;
            }
        }
        return count;
    }
};