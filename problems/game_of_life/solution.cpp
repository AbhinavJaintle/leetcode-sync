class Solution {
public:
    vector<vector<int>> v = {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> ans(board.size(),vector<int>(board[0].size()));
        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[0].size(); j++){
                int o = 0;
                for(auto&k:v){
                    if(i+k[0]>=0&&i+k[0]<board.size()&&j+k[1]>=0&&j+k[1]<board[0].size()){
                        if(board[i+k[0]][j+k[1]])o++;
                    }
                }
                if(board[i][j]==0){
                    if(o==3)ans[i][j]=1;
                    else ans[i][j]=0;
                }
                else{
                    if(o==3||o==2)ans[i][j]=1;
                    else ans[i][j]=0;
                }
            }
        }
        for(int i = 0; i<board.size(); i++){
            for(int j = 0; j<board[0].size(); j++){
                board[i][j]=ans[i][j];
            }
        }
    }
};