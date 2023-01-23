class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        for(int i = 0; i<mat.size(); i++){
            for(int j = 0; j<mat[0].size(); j++){
                if(i-1>=0&&mat[i][j]<=mat[i-1][j]) continue;
                if(j-1>=0&&mat[i][j]<=mat[i][j-1]) continue;
                if(i+1<mat.size()&&mat[i][j]<=mat[i+1][j]) continue;
                if(j+1<mat[0].size()&&mat[i][j]<=mat[i][j+1]) continue;
                return {i,j};
            }
        }
        return {-1,-1};
    }
};