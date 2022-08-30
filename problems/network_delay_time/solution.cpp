class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        queue<int> q;
        vector<vector<pair<int,int>>> adj(n+1,vector<pair<int,int>>{});
        vector<int> vis(n+1,0);
        vector<int> time(n+1,0);
        
        
        for(auto&i:times){
            adj[i[0]].push_back({i[1],i[2]});            
        }
        q.push(k);
        while(!q.empty()){
            int temp = q.front();
            q.pop();
            vis[temp]=1;
            for(auto&i:adj[temp]){
                if(vis[i.first]==0||time[i.first]>i.second+time[temp]){
                    q.push(i.first);
                    vis[i.first]=1;
                    time[i.first]=i.second+time[temp];
                }
            }
        }
        for(int i = 1; i<n+1; i++){
           if(vis[i]==0){ 
            return -1;
           }
        }
        return *max_element(time.begin(),time.end());
    }
};