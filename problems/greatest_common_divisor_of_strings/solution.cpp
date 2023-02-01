class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int t = __gcd(str1.length(),str2.length());
        string temp;
        for(int i = 0; i<t; i++){
            temp.push_back(str1[i]);
        }
        string t1;
        for(int i = 0; i<str1.length()/t; i++){
            t1+=temp;
        }
        if(t1!=str1)return "";
        t1="";
        for(int i = 0; i<str2.length()/t; i++){
            t1+=temp;
        }
        if(t1!=str2)return "";
        return temp;
    }
};