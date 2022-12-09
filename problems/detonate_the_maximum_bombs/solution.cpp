class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        unordered_map<int,vector<int>> m;
        for(int i = 0; i<bombs.size(); i++){
            int x = bombs[i][0];
            int y = bombs[i][1];
            int r = bombs[i][2];
            for(int j = 0; j<bombs.size(); j++){
                if(i!=j){
                    int xtemp = bombs[j][0];
                    int ytemp = bombs[j][1];
                    if(sqrt(pow(x-xtemp,2)+pow(y-ytemp,2))<=r){
                        m[i].push_back(j);
                    }
                }
            }
        }
        int count = 0;
        for(int i = 0; i<bombs.size(); i++){
            unordered_map<int,int> vis;
            
            queue<int>q;
            q.push(i);
            int ctemp = 0;
            while(!q.empty()){
                int temp = q.front();
                q.pop();
                if(vis[temp]==1){
                    continue;
                }
                vis[temp]=1;
                ctemp++;
                for(auto&j:m[temp]){
                    q.push(j);
                }
            }
            count=max(count,ctemp);
            vis.clear();
        }
        return count;
    }
};