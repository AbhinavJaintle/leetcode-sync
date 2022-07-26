class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0; i<9; i++){
            map<int,int> m1;
            for(int j = 0; j<9; j++){
                if(board[j][i]=='.'){
                    continue;
                }
                if(m1[board[j][i]]!=0){
                    return false;
                }
                m1[board[j][i]] = board[j][i];  
            }
        }
        for(int i = 0; i<9; i++){
            map<int, int> m2;
            for(int j = 0; j<9; j++){
                if(board[i][j]=='.'){
                    continue;
                }
                if(m2[board[i][j]]!=0){
                    return false;
                }
                m2[board[i][j]] = board[i][j];  
            }
        }
          
        map<string,int> m3;
        for(int k = 0; k<9;k++){
            for(int r = 0; r<9; r++){
                if(board[k][r]=='.'){
                    continue;
                }
                int temp = 3*(k/3)+r/3;
                string has = to_string(temp) + "#" + board[k][r];
                if(m3[has]!=0){
                    return false;
                }
                m3[has] = 1;
            }
        }
        
        return true;
    }
};