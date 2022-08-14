class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> ans(n-2, vector<int>(n-2,-1));
        for(int i = 1; i<grid.size()-1;i++){
            for(int j = 1; j<grid[0].size()-1; j++){
                ans[i-1][j-1]=max({grid[i-1][j-1],grid[i][j-1],grid[i-1][j],grid[i][j],grid[i+1][j+1],grid[i][j+1],grid[i+1][j],grid[i-1][j+1],grid[i+1][j-1]});
                
            }
        }
        return ans;
    }
};