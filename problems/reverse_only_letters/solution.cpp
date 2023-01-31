class Solution {
public:
    string reverseOnlyLetters(string s) {
        vector<char> v;
        for(auto&i:s){
            if((i>64&&i<91)||(i>96&&i<123)){
                v.push_back(i);
            }
        }
        int index=v.size()-1;
        for(auto&i:s){
            if((i>64&&i<91)||(i>96&&i<123)){
                i=v[index];
                index--;
            }
        }
        return s;
    }
};