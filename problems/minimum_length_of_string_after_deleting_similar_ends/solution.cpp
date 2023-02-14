class Solution {
public:
    int minimumLength(string s) {
        int st = 0;
        int e = s.length()-1;
        char prev = s[st];
        if(s[e]==prev){
            while(st<e){
                while(st<s.length()&&s[st]==prev){
                    st++;
                }
                while(e>=0&&s[e]==prev){
                    e--;
                }
                if(st<s.length())prev=s[st];
                if(e>=0&&prev!=s[e]&&st<e)return e-st+1;
            }return st==e?1:0;
        }
        return s.length();
    }
};