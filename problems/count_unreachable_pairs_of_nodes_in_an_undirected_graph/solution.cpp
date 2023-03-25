class Solution {
public:
    long long helper(int root, unordered_map<int,int>& m, vector<vector<int>>& adj){
        long long sum = 1;
        m[root]++;
        for(auto&i:adj[root]){
            if(!m[i]){
                sum+=helper(i,m,adj);
            }
        }
        return sum;
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long ans = 0;
        vector<long long> v;
        vector<vector<int>> adj(n);
        for(auto&i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        unordered_map<int,int> m;
        long long curr=0;
        for(int i = 0; i<n; i++){
            if(!m[i]){
                long long a = helper(i,m,adj);
                ans+=curr*a;
                curr+=a;
            }
        }
    
        return ans;
    }
};