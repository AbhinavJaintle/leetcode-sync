class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        vector<int> v;
        for(int i = 0; i<grid[0].size(); i++){
            int col = i;
            int row = -1;
            int flag = 0;
            while(row!=grid.size()-1){
                if(col<0||col>=grid[0].size()||col+grid[row+1][col]<0||col+grid[row+1][col]>=grid[0].size()){
                    v.push_back(-1);
                    flag=1;
                    break;
                }
                if(grid[row+1][col]!=grid[row+1][col+grid[row+1][col]]){
                    v.push_back(-1);
                    flag=1;
                    break;
                }
                col+=grid[row+1][col];
                row++;
            }
            if(flag==0){
                v.push_back(col);
            }
        }
        return v;
    }
};