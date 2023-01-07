class Solution {
public:
    double myPow(double x, int n) {
        if(x==1.00000) return x;
        if(x==-1){
            if(n%2==0) return 1;
            return -1;
        }
        long long t = (long long) n;
        double ans = 1.00000;
        if(t<0){
            t*=-1; 
            x=1/x;
        }
        for(long long i = 1; i<=t; i++){
            ans*=x;
            if(ans==0) return ans;
        }
        return ans;
    }
};