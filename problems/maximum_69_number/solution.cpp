class Solution {
public:
    int maximum69Number (int num) {
        string temp = to_string(num);
        for(auto&i:temp){
            if(i=='6'){
                i='9';
                break;
            }
        }
        return stoi(temp);
    }
};