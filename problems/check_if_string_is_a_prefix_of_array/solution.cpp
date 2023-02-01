class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string temp="";
        int index=0;
        while(index<words.size()&&temp.length()<s.length()){
            temp+=words[index];
            index++;
        }
        return temp==s;
    }
};