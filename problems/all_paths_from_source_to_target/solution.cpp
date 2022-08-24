class Solution {
    vector<vector<int>> ans;
public:
    
    void wonderful(vector<vector<int>> adj, int index, vector<int> curr){
        if(index==adj.size()-1){
            ans.push_back(curr);
            return;
        }
        for(int i = 0; i<adj[index].size(); i++){
            curr.push_back(adj[index][i]);
            wonderful(adj,adj[index][i],curr);
            curr.pop_back();
        }
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        ans.clear();
        vector<int> curr;
        curr.push_back(0);
        wonderful(graph,0,curr);
        return ans;
    }
};