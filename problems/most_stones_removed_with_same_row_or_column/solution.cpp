class Solution {
public:
    int ans=0;
    
   void dfs(int i,vector<vector<int>>&stones,vector<int>&vis){
        
        vis[i]=1;

        for(int j=0;j<stones.size();j++){
            if(!vis[j] && (stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1])){
                ans++;
                dfs(j,stones,vis);
            }   
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        vector<int>vis(stones.size());
        
        for(int i=0;i<stones.size();i++){
            if(!vis[i]){
                dfs(i,stones,vis);
            }
        }
        
        return ans;
    }
};