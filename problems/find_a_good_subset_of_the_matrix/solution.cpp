class Solution {
public:
    vector<int> goodSubsetofBinaryMatrix(vector<vector<int>>& grid) {
        vector<int> temp(grid[0].size(),0);
        for(int i = 0; i<grid.size(); i++){
            if(grid[i]==temp)return {i};
        }
        for(int i = 0; i<grid.size(); i++){
            temp = grid[i];
            for(int j = i+1; j<grid.size(); j++){
                bool flag = true;
                for(int k = 0; k<temp.size(); k++){
                    if(temp[k]+grid[j][k]>1){
                        flag=false;
                        break;
                    }
                }
                if(flag)return {i,j};
            }
        }
        return {};
    }
};