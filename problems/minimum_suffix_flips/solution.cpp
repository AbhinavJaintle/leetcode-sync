class Solution {
public:
    int minFlips(string target) {
        int curr = 0;
        int sum = 0;
        for(auto&i:target){
            if(i-'0'!=curr){
                curr=i-'0';
                sum++;
            }
        }
        return sum;
    }
};