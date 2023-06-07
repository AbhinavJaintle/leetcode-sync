class Solution {
public:
    int minFlips(int a, int b, int c) {
        int count=0;
        while(a||b||c){
            if(((a&1)||(b&1))!=(c&1)){
                if((c&1)==0){
                    if((a&1)==1)count++;
                    if((b&1)==1)count++;
                }
                else{
                    count++;
                }
            }
            a=a>>1;
            b=b>>1;
            c=c>>1;
        }
        return count;
    }
};