class Solution {
public:
	void dfs(int node,vector<int> &vis,vector<int> adj[]){
		vis[node]=1;

		for(auto x:adj[node]){
			if(!vis[x])
				dfs(x,vis,adj);
		}
	}

	vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {

		vector<int> adj[n];
		vector<vector<int>> ans(n);

		for(auto i:edges)
			adj[i[0]].push_back(i[1]);

		for(int i=0;i<n;i++){

			vector<int> vis(n,0);
			dfs(i,vis,adj);

			for(int j=0;j<n;j++){
				if(i!=j and vis[j])
					ans[j].push_back(i);
			}
		}

		return ans;
	}
};