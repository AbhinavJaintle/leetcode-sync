class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for(int i = 0; i<manager.size(); i++){
            if(manager[i]!=-1) adj[manager[i]].push_back(i);
        }
        queue<pair<int,int>> q;
        q.push({headID,0});
        int sum=0;
        while(!q.empty()){
            int t = q.front().first;
            int s = q.front().second;
            sum=max(s,sum);
            q.pop();
            if(adj[t].size()!=0){
             for(auto&i:adj[t]){
                q.push({i,informTime[t]+s});
             }
            }
        }
        return sum;
    }
};