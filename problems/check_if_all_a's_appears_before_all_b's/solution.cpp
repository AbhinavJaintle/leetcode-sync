class Solution {
public:
    bool checkString(string s) {
        bool flag=false;
        for(auto&i:s){
            if(i=='a'){
                if(flag)return false;
            }
            if(i=='b')flag=true;
        }
        return true;
    }
};