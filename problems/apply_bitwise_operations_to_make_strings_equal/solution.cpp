class Solution {
public:
    bool makeStringsEqual(string s, string target) {
        int ones=0, x=0,o=0;
        for(int i = 0; i<target.length(); i++){
            if(s[i]=='1')ones++;
            if(s[i]==target[i])continue;
            else{
                if(s[i]=='0')o++;
                else x++;
            }
        }
        if(ones==0&&(x>0||o>0))return false;
        ones+=o;
        if(x==0)return true;
        return ones>x;
    }
};