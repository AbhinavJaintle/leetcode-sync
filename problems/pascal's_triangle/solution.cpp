class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> v(1, vector<int>(1));
        vector<vector<int>> ans;
        v[0][0] = 1;
        ans.push_back(v[0]);
        for(int i = 1; i<numRows; i++){
            v.resize(i+1,vector<int>(i+1));
            v[i][0] = 1;
            v[i][i] = 1;
            for(int j = 1; j<v.size()-1; j++){
                v[i][j] = v[i-1][j-1]+v[i-1][j];
            }
            ans.push_back(v[i]);
        }
        return ans;
    }
    
};