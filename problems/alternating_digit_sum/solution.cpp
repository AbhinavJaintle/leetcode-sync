class Solution {
public:
    int alternateDigitSum(int n) {
        int sign = 1;
        int sum=0;
        string temp = to_string(n);
        for(auto&i:temp){
            sum+=sign*(i-'0');
            sign=sign==1?-1:1;
        }
        return sum;
    }
};