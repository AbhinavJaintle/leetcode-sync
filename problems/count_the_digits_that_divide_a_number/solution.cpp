class Solution {
public:
    int countDigits(int num) {
        int count=0;
        string temp = to_string(num);
        for(auto&i:temp){
            if(num%(i-'0')==0){
                count++;
            }
        }
        return count;
    }
};