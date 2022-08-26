class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& E) {
        int n = E.size() ; 
    
        vector<int> indegree(n) ; 
        
        vector<vector<int>> adj(n) ; 
        
        for(auto it:E){
            adj[it[0]-1].push_back(it[1]-1) ; 
            adj[it[1]-1].push_back(it[0]-1) ; 
            indegree[it[1]-1]++; 
            indegree[it[0]-1]++;
        }
        
                
        queue<int> q ; 
        
        vector<bool> vis(n,false) ; 
        
        for(int i = 0 ; i<n ;i++){
            if(indegree[i]==1){
              q.push(i) ;   
              vis[i] = true ; 
            } 
        }
        
        
        while(!q.empty()){
            int temp = q.front() ; 
            q.pop() ;
                  
            for(auto it:adj[temp]){
                indegree[it]-- ;
                if(indegree[it]==1){
                    q.push(it) ; 
                    vis[it] = true; 
                }
            }
        }
        
        vector<int> ans ; 
        
        for(int i = n-1 ; i>=0 ; i--){
            if(!vis[E[i][0]-1] && !vis[E[i][1]-1]){
                ans = E[i] ; 
                break ; 
            }
        }
        
        
        return ans ;
        
    }
};