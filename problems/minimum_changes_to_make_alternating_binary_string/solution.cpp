class Solution {
public:
    int helper(string s, char start){
        int sum = 0;
        for(auto&i:s){
            if(i!=start){
                sum++;
            }
            start=start=='1'?'0':'1';
        }
        return sum;
    }
    int minOperations(string s) {
        return min(helper(s,'0'),helper(s,'1'));
    }
};