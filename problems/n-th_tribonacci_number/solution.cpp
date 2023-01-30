class Solution {
    unordered_map<int,int>m;
public:
    int tribonacci(int n) {
        if(n==0)return 0;
        if(n==1)return 1;
        if(n==2)return 1;
        if(m[n])return m[n];
        return m[n]=tribonacci(n-3)+tribonacci(n-2)+tribonacci(n-1);
    }
};