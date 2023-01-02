class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.length()==1) return true;
        if(word[0]<91){
            if(word[1]<91){
                for(auto&i:word){
                    if(i>90) return false;
                }
            }
            else{
                for(int i = 1; i<word.length(); i++){
                    if(word[i]<91) return false;
                }
            }
        }
        else{
            for(auto&i:word){
                if(i<91) return false;
            }
        }
        return true;
    }
};