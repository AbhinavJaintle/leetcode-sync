class Solution {
    unordered_map<int,int> vis;
public:
    int helper(int index, vector<vector<int>>& adj, vector<bool>& hasApple){
        int sum=0;
        if(hasApple[index]&&index!=0) sum++;
        vis[index]++;
        int nums=0;
        for(auto&i:adj[index]){
            if(vis[i]==0){
                sum+=helper(i,adj,hasApple);
                nums++;
            }
        }
        if(nums>0&&sum>0&&!hasApple[index]&&index!=0){
            sum++;
        }
        return sum;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for(auto&i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        
        return 2*helper(0,adj,hasApple);
    }
};