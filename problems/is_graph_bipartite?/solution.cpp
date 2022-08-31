class Solution {
public:
    bool dfs(int index, vector<vector<int>>& graph, map<int,int>& m,int flag){
        if(m[index]!=0){
            if(m[index]==flag){
                return true;
            }
            return false;
        }
        m[index]=flag;
        int temp = (flag==1)?2:1;
        for(auto&i: graph[index]){
            if(!dfs(i,graph,m,temp)){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        map<int,int> m;
        for(int i = 0; i<graph.size();i++){
            if(m[i]==0){
                if(!dfs(i,graph,m,1)){
                    return false;
                }
            }
        }
        return true;
    }
};