class NumMatrix {
    vector<vector<int>> v;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        v=matrix;
        for(int i = 0; i<v.size(); i++){
            for(int j = 1; j<v[0].size(); j++){
                v[i][j]+=v[i][j-1];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for(int i = row1; i<=row2; i++){
            sum = col1==0? sum+v[i][col2]:sum+v[i][col2]-v[i][col1-1];
        }
        return sum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */