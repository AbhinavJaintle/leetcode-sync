class Solution {
public:
    int minimumMoves(string s) {
        int moves=0;
        for(int i = 0; i<s.length(); i++){
            if(s[i]=='X'){
                int index=0;
                moves++;
                while(i<s.length()&&index<3){
                    i++;
                    index++;
                }
                i--;
            }
        }
        return moves;
    }
};