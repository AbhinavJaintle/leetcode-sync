class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1)  return {0} ;
        
        vector<vector<int>> adj(n) ;
        vector<int> deg(n,0) ;
        
        for(auto it : edges)    
        {
            adj[it[0]].push_back(it[1]) ;
            adj[it[1]].push_back(it[0]) ;
            deg[it[0]]++ , deg[it[1]]++ ;
        }
        
        queue<int> q ;
        stack<int> st ;      // used to store topological order
        
        for(int i=0 ; i<n ; i++)
        {
            if(deg[i] == 1)  q.push(i)  ;    // here we check for deg=1 instead of 0  because tree is undirected so it has minimum of 1 degree of leaf nodes 
        }
        
        while(!q.empty())
        {
            int sz=q.size() ;
            while(sz--)
            {
                int cur = q.front() ;
                q.pop() ;
                st.push(cur) ;     //   inserting element in the stack in topological order
                for(auto child : adj[cur])
                {
                    deg[child]-- ;
                    if(deg[child] == 1)   q.push(child) ;
                }
            }
            st.push(-1) ;   //  -1 is used to denote that all nodes of same particular pushed in the stack and there is no other node of that degree in the tree.  
        }
        
        st.pop() ;
        vector<int> ans ;
        //   node with highest degrees will be stored in the ans vector because centroid will always lie closer to 
		//   the higher degree nodes .
		//   For eg : A tree contains node of degree 1,2,3,.. so first nodes with degree 1 will be removed and nodes with degree two becomes nodes with degree one and so on.... at the end only those nodes will be present where centroid will lie.
        while(!st.empty() && st.top() != -1)  ans.push_back(st.top()) , st.pop();
        
        return ans ;
    }
};