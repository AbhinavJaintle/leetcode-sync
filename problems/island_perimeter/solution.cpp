class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        vector<vector<int>> dir = {{-1,0},{0,-1},{1,0},{0,1}};
        int per = 0;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                if(grid[i][j]==1){
                    for(auto&k:dir){
                        if(i+k[0]<0||i+k[0]>=grid.size()){
                            per++;
                        }
                        if(j+k[1]<0||j+k[1]>=grid[0].size()){
                            per++;
                        }
                    }
                }
                else{
                    for(auto&k:dir){
                        if(i+k[0]>=0&&i+k[0]<grid.size()&&j+k[1]>=0&&j+k[1]<grid[0].size()){
                            if(grid[i+k[0]][j+k[1]]==1){
                                per++;
                            }
                        }
                    }
                }
            }
        }
        return per;
    }
};