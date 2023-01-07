class Solution {
    // struct vec{
    //     vector<int>(2,0) data;
    //     vec(data) : {0,0}{}
    // };
    map<pair<int,int>,int> vis;
    vector<pair<int,int>> dir = {{-1,0},{0,-1},{1,0},{0,1}};
    bool flag=true;
public:
    void helper(int i, int j, vector<vector<int>>& grid){
        if((i==0||i==grid.size()-1||j==0||j==grid[0].size()-1)&&grid[i][j]==0){
            flag=false;
            return;
        }
        if(grid[i][j]==1) return;
        vis[{i,j}]++;
        for(auto&k:dir){
            if(vis[{i+k.first,j+k.second}]!=1){
                helper(i+k.first,j+k.second,grid);
            }
        }
        return;
    }
    int closedIsland(vector<vector<int>>& grid) {
        vis.clear();
        int count=0;
        for(int i = 0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]==0&&vis[{i,j}]==0){
                    helper(i,j,grid);
                    if(flag==true) count++;
                    flag=true;
                }
            }
        }
        return count;
    }
};