class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        vector<int> v;
        v.push_back(matrix[0][0]);
        for(int i = 1; i<matrix[0].size(); i++){
            matrix[0][i]=matrix[0][i]^matrix[0][i-1];
            v.push_back(matrix[0][i]);
        }
        for(int i = 1; i<matrix.size(); i++){
            int curr = matrix[i][0];
            matrix[i][0] = curr^matrix[i-1][0];
            v.push_back(matrix[i][0]);
            for(int j = 1; j<matrix[0].size(); j++){
                curr=curr^matrix[i][j];
                matrix[i][j] = curr^matrix[i-1][j];
                v.push_back(matrix[i][j]);
            }
        }
        sort(v.begin(),v.end(),greater<int>());
        return v[k-1];
    }
};