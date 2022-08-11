class Solution {
public:
    int hammingWeight(uint32_t n) {
        int i = 32;
        int num = 0;
        while(i--){
            if(n&1==1){
                num++;
            }
            n=n>>1;
        }
        return num;
    }
};