class Solution {
public:
    bool helper(vector<vector<int>>& matrix, int x, int y){
        int limx = matrix.size();
        int limy = matrix[0].size();
        int target = matrix[x][y];
        x+=1;
        y+=1;
        while(x<limx&&y<limy){
            if(matrix[x][y]!=target){
                return false;
            }
            x++;
            y++;
        }
        return true;
    }
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for(int i = 0; i<matrix[0].size(); i++){
            if(!helper(matrix,0,i)){
                return false;
            }
        }
        for(int i = 0; i<matrix.size(); i++){
            if(!helper(matrix,i,0)){
                return false;
            }
        }
        return true;
    }
};