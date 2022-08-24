class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        map<int,int> m;
        for(int i = 0; i<edges.size(); i++){
            for(int j = 0; j<edges[0].size(); j++){
                m[edges[i][j]]+=1;
            }
        }
        for(auto& i: m){
            if(i.second==edges.size()){
                return i.first;
            }
        }
        return -1;
    }
};