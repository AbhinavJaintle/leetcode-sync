class Solution {
public:
    string alphabetBoardPath(string target) {
        string ans;
        int x = 0;
        int y = 0;
        for(auto&i:target){
            int tempx = (i-'a')/5;
            int tempy = (i-'a')%5;
            if(tempy<y){
                for(int i = 0; i<y-tempy; i++){
                    ans.push_back('L');
                }
            }
            if(tempx<x){
                for(int i = 0; i<x-tempx; i++){
                    ans.push_back('U');
                }
            }
            if(tempy>y){
                for(int i = 0; i<tempy-y; i++){
                    ans.push_back('R');
                }
            }
            
            if(tempx>x){
                for(int i = 0; i<tempx-x; i++){
                    ans.push_back('D');
                }
            }
            
            ans.push_back('!');
            x=tempx;
            y=tempy;
        }
        return ans;
    }
};