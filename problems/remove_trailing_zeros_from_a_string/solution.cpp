class Solution {
public:
    string removeTrailingZeros(string num) {
        int index = num.size()-1;
        while(index>=0&&num[index]=='0'){
            index--;
        }
        string s;
        for(int i = 0; i<=index; i++){
            s.push_back(num[i]);
        }
        return s;
    }
};