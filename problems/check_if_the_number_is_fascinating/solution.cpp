class Solution {
public:
    bool isFascinating(int n) {
        string temp = to_string(n)+to_string(2*n)+to_string(3*n);
        sort(temp.begin(),temp.end());
        return temp=="123456789";
    }
};