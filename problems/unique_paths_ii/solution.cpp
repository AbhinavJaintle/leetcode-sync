class Solution {
public:
 
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> df(obstacleGrid.size(),vector<int> (obstacleGrid[0].size(), -1));
        
        df[0][0] = 1;
        if(obstacleGrid[0][0]==1)return 0;
        
        for(int i = 0; i<obstacleGrid.size(); i++){
            for(int j = 0; j<(obstacleGrid[0].size()); j++){
                
                if(df[i][j]!=-1){
                   continue; 
                }
                
                else if(obstacleGrid[i][j]!=1){
                    int point1 = (i>0)? df[i-1][j]:0;
                    int point2 = (j>0)? df[i][j-1]:0; 
                    df[i][j] = point1+point2;
                }
                else{
                    df[i][j] =  0;
                }
                
            }
            
        }
        return df[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
    }
};