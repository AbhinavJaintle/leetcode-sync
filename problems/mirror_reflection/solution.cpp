class Solution {
public:
    int lcm(int a, int b){
        for(int i = a; i<a*b; i++){
            if(i%a==0&&i%b==0){
                return i;
            }
            else{
                continue;
            }
        }
        return a*b;
    }
    int mirrorReflection(int p, int q) {
        int ans = lcm(p,q);
        int m = ans/p;
        int n = ans/q;
        if(m%2==0&&n%2!=0){
                return 0;
        }
        else if(m%2!=0&&n%2==0){
            return 2;
        }
        else if(m%2!=0&&n%2!=0){
            return 1;
        }
        return -1;
        
    }
};