class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int i=32;
        uint32_t k=0;
    while(i--){
      k<<=1;
        k=(k|(n&1));
        n>>=1;
        }
        return k;
    }
};