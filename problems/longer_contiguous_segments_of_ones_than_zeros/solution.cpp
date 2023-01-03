class Solution {
public:
    bool checkZeroOnes(string s) {
        int one = 0;
        int zero = 0;
        int onestreak=0;
        int zerostreak=0;
        char prev='2';
        for(auto&i:s){
            if(i==prev){
                if(i=='1'){
                    onestreak++;
                }
                else{
                    zerostreak++;
                }
            }
            else{
                one=max(one,onestreak);
                zero=max(zero,zerostreak);
                onestreak=i=='1'?1:0;
                zerostreak=i=='0'?1:0;
                prev=i;
            }
        }
        one=max(one,onestreak);
        zero=max(zero,zerostreak);
        return one>zero;
    }
};