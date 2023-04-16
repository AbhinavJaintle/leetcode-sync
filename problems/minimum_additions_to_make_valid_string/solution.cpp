class Solution {
public:
    int addMinimum(string word) {
        int count=0;
        for(int i = 0; i<word.length(); i++){
            if(word[i]=='a'){
                if(i==word.length()-1){
                    count+=2;
                    break;
                }
                if(word[i+1]!='b'){
                    if(word[i+1]=='c'){
                        count++;
                        i++;
                    }
                    else if(word[i+1]=='a'){
                        count+=2;
                    }
                    continue;
                }
                if(i==word.length()-2){
                    count+=1;
                    break;
                }
                if(word[i+2]!='c'){
                    count++;
                    i++;
                    continue;
                }
                i+=2;
                continue;
            }
            if(word[i]=='b'){
                count++;
                if(i==word.length()-1){
                    count+=1;
                    break;
                }
                if(word[i+1]!='c'){
                    count++;
                    continue;
                }
                i++;
                continue;
            }
            if(word[i]=='c'){
                count+=2;
            }
        }
        return count;
    }
};