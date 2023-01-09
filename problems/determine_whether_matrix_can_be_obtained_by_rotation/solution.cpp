class Solution {
    vector<vector<int>> temp={};
public:
    bool helper(vector<vector<int>>& mat, vector<vector<int>>& target, int curr){
        if(mat==target) return true;
        if(curr==3) return false;
        
        for(int i = 0; i<mat.size(); i++){
            for(int j = 0; j<mat[0].size(); j++){
                temp[i][j]=mat[mat[0].size()-1-j][i];
            }
        }
        mat=temp;
        return helper(mat,target,curr+1);
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        temp=mat;
        return helper(mat,target,0);
    }
};