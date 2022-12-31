class Solution {
    vector<pair<int,int>> dir ={{-1,0},{1,0},{0,-1},{0,1}};
public:
    int dfs(int x, int y,vector<vector<int>>& grid, map<pair<int,int>,int>& vis, int curr, int n){
        if(x<0||x>=grid.size()||y<0||y>=grid[0].size()||grid[x][y]==-1||vis[{x,y}]==1){
            return 0;
        }
        if(grid[x][y]==2){
            if(curr==n+1){
                return 1;
            }
            return 0;
        }
        vis[{x,y}]=1;
        curr++;
        int sum=0;
        for(auto&i:dir){
            sum+=dfs(x+i.first,y+i.second,grid,vis,curr,n);
        }
        vis[{x,y}]=0;
        return sum;
    }
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n= 0;
        int x;
        int y;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j]==0){
                    n++;
                }
                else if(grid[i][j]==1){
                    x=i;
                    y=j;
                }
            }
        }
        map<pair<int,int>,int> vis;
        return dfs(x,y,grid,vis,0,n);
    }
};