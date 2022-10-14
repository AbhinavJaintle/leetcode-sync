class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        for(int i = 0; i<mat.size(); i++){
            for(int j = 0; j<mat[0].size(); j++){
                if(i==j){
                    if(j==mat[0].size()-i-1){
                        sum+=mat[i][j];
                    }
                    else{
                        sum+=mat[i][j]+mat[i][mat[0].size()-i-1];
                    }
                }
            }
        }
        return sum;
    }
};