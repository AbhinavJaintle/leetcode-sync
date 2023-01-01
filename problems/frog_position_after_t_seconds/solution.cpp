class Solution {
public:
    double dfs(int index, vector<vector<int>>& adj, unordered_map<int,int>&vis, double curr, int target,int currt, int t){
        if(currt==t){
            if(index==target){
                return curr;
            }
            return 0;
        }
        vis[index]++;
        int count=0;
        for(auto&i:adj[index]){
            if(vis[i]==0){
                count++;
            }
        }
        if(count==0){
            vis[index]--;
            if(index==target){
                return curr;
            }
            else{
                return 0;
            }
        }
        if(index==target){
            vis[index]--;
            return 0;
        }
        double sum = 0;
        for(auto&i:adj[index]){
            if(vis[i]==0){
                sum+=dfs(i,adj,vis,curr*((double)1/count),target,currt+1,t);
            }
        }
        return sum;
    }
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> adj(n+1);
        unordered_map<int,int> vis;
        for(auto&i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        double curr = 1.000000;
        vis[1]++;
        return dfs(1,adj,vis,curr,target,0,t);
    }
};