class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        for(int i =0; i<mat.size(); i++){
            for(int j = 1; j<mat[0].size(); j++){
                mat[i][j]+=mat[i][j-1];
            }
        }
        vector<vector<int>> ans(mat.size(),vector<int>(mat[0].size()));
        for(int i =0; i<mat.size(); i++){
            for(int j = 0; j<mat[0].size(); j++){
                int temp = 0;
                int xs = i-k<0?0:i-k;
                int xe = i+k>=mat.size()?mat.size()-1:i+k;
                int ys = j-k-1<0?-1:j-k-1;
                int ye = j+k>=mat[0].size()?mat[0].size()-1:j+k;
                for(int k = xs; k<=xe; k++){
                    temp=ys==-1?temp+mat[k][ye]:temp+mat[k][ye]-mat[k][ys];
                }
                ans[i][j]=temp;
            }
        }
        return ans;
    }
};