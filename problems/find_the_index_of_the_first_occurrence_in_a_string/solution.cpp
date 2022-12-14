class Solution {
public:
    int strStr(string haystack, string needle) {
        
        for(int i = 0; i<haystack.length(); i++){
            if(haystack[i]==needle[0]){
                for(int j = 1; j<needle.length()+1; j++){
                    if(j==needle.length()){
                        return i;
                    }
                    if(haystack[i+j]!=needle[j]){
                        break;
                    }
                }
            }
        }
        return -1;
    }
};