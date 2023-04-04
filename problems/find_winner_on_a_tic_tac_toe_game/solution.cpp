class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int>> arr(3);
        for (int i = 0; i < 3; i++){
            arr[i] = {0, 0, 0};
        } 
        for (int i = 0; i < moves.size(); i++){
            if (i % 2 == 0){
                arr[moves[i][0]][moves[i][1]]++;
            } else {
                arr[moves[i][0]][moves[i][1]] += 2;
            }
        }
        for (auto i: arr) {
            int a = 0;
            int b = 0;
            for (auto j: i){
                if (j == 1){
                    a++;
                } else if (j == 2){
                    b++;
                }
            }
            if (a == 3){
                return "A";
            } else if (b == 3){
                return "B";
            }
        }
        for (int i = 0; i < 3; i++){
            int a = 0;
            int b = 0;
            for (int j = 0; j < 3; j++){
                if (arr[j][i] == 1){
                    a++;
                } else if (arr[j][i] == 2){
                    b++;
                }
            }
            if (a == 3){
                return "A";
            } else if (b == 3){
                return "B";
            }
        }
        bool a = arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2] && arr[0][0] == 1;
        if (a){
            return "A";
        }
        a = arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0] && arr[0][2] == 1;
        if (a){
            return "A";
        }
        a = arr[0][0] == arr[1][1] && arr[0][0] == arr[2][2] && arr[0][0] == 2;
        if (a){
            return "B";
        }
        a = arr[0][2] == arr[1][1] && arr[0][2] == arr[2][0] && arr[0][2] == 2;
        if (a){
            return "B";
        }
        if (moves.size() != 9){
            return "Pending";
        }
        return "Draw";
    }
};