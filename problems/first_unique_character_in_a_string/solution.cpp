class Solution {
public:
    int firstUniqChar(string s) {
        for(int i = 0; i<s.length(); i++){
            int num = 0;
            for(int j = 0; j<s.length(); j++){
                if(s[i]==s[j]&&j!=i){
                    num++;
                    break;
                }
            }
            if(num==0){
                return i;
            }
        }
        return -1;
    }
        
};