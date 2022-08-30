class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<stack<int>> vs(matrix[0].size());
        for(int i = 0; i<matrix[0].size(); i++){
            for(int j = 0; j<matrix.size(); j++){
                vs[i].push(matrix[j][i]);
            }
        }
        for(int i = 0; i<matrix.size(); i++){
            for(int j= 0; j<matrix[0].size(); j++){
                matrix[i][j]=vs[i].top();
                vs[i].pop();
            }
        }
        return;
    }
};