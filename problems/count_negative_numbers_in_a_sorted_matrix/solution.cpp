class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int row = grid.size()-1;
        int col = grid[0].size()-1;
        int curr = 0;
        int count=0;
        while(row>=0&&curr<grid[0].size()){
            while(col>=0&&col>=curr){
                if(grid[row][col]<0)count++;
                else{
                    curr=col+1;
                    break;
                }
                col--;
            }
            col=grid[0].size()-1;
            row--;
        }
        return count;
    }
};