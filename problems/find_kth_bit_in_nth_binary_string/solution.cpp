class Solution {
public:
    char findKthBit(int n, int k) {
        if(n==1){
            return '0'; 
        }
        if(pow(2,n)/k==2){
            return '1';
        }
        if(k<pow(2,n)/2){
            return findKthBit(n-1,k);
        }
        k = pow(2,n)-k;
        if(findKthBit(n-1,k)=='1'){
            return '0';
        }
        return '1';
    }
};