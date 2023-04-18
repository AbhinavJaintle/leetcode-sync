class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int index = 0;
        bool flag = true;
        string temp;
        while(index<min(word1.length(),word2.length())){
            if(flag){
                flag=!flag;
                temp.push_back(word1[index]);
            }
            else{
                flag=!flag;
                temp.push_back(word2[index++]);
            }
        }
        while(index<word1.length()){
            temp.push_back(word1[index++]);
        }
        while(index<word2.length()){
            temp.push_back(word2[index++]);
        }
        return temp;
    }
};