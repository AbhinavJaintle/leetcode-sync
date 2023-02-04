class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>=s2.length()){
            sort(s1.begin(),s1.end());
            sort(s2.begin(),s2.end());
            return s1==s2;
        }
        int len = s1.length();
        sort(s1.begin(),s1.end());

        for(int i = 0; i<=s2.length()-len; i++){
            string temp = s2.substr(i,len);
            sort(temp.begin(),temp.end());
            if(temp==s1)return true;
        }
        return false;
    }
};