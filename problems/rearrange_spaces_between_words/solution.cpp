class Solution {
public:
    string reorderSpaces(string text) {
        int count=0;
        char prev=' ';
        int sz=0;
        for(auto&i:text){
            if(i==' '){ 
                count++;
            }
            else if(prev==' ') sz++;
            prev=i;
        }
        stringstream ss(text);
        string word;
        string ans="";
        if(sz==1){
            ss>>word;
            ans=word;
            for(int i = 0; i<count; i++){
                ans.push_back(' ');
            }
            return ans;
        }
        int index=0;
        while(ss>>word){
            ans+=word;
            if(index==sz-1){
                for(int i = 0; i<count%(sz-1); i++){
                    ans.push_back(' ');
                }
                break;
            }
            for(int i = 0; i<count/(sz-1); i++){
                ans.push_back(' ');
            }
            index++;
        }
        return ans;
    }
};