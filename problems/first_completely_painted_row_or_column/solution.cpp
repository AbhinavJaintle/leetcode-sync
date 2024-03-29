class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,pair<int,int>> m;
        unordered_map<int,int> row;
        unordered_map<int,int> col;
        for(int i = 0; i<mat.size(); i++){
            for(int j = 0; j<mat[0].size(); j++){
                m[mat[i][j]] = {i,j};
            }
        }
        for(int i = 0; i<arr.size(); i++){
            row[m[arr[i]].first]++;
            col[m[arr[i]].second]++;
            if(row[m[arr[i]].first]==mat[0].size()||col[m[arr[i]].second]==mat.size())return i;
        }
        return -1;
    }
};