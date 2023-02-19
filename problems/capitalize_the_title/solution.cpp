class Solution {
public:
    string capitalizeTitle(string title) {
        stringstream ss(title);
        string word;
        string n="";
        while(ss>>word){
            if(word.length()<3){
                for(auto&i:word){
                    if(i<91){
                        i+=32;
                    }
                }
            }
            else{
                if(word[0]>91)word[0]-=32;
                for(int i = 1; i<word.length(); i++){
                    if(word[i]<91)word[i]+=32;
                }
            }
            n+=word+" ";
        }
        n.pop_back();
        return n;
    }
};