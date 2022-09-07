class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> col(grid[0].size(),0);
        vector<int> row(grid.size(),0);
        for(int i = 0; i<grid.size(); i++){
            row[i] = *max_element(grid[i].begin(), grid[i].end());
        }
        for(int i = 0; i<grid[0].size(); i++){
            int temp = 0;
            for(int j = 0; j<grid.size(); j++){
                temp = max(temp,grid[j][i]);
            }
            col[i] = temp;
        }
        int count = 0;
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                count += min(row[i],col[j])-grid[i][j];
            }
        }
        return count;
    }
};