class Solution {
public:
    int mod = 1e9+7;
    int binpow(long long a, long long b, long long m) {
        a %= m;
        long long res = 1;
        while (b > 0) {
            if (b & 1)
                res = (res%m * a % m)%m;
            a = (a%m * a % m)%m;
            b >>= 1;
        }
    return (int)res-2;
}
    int monkeyMove(int n) {
        return ((binpow(2,(long long)n,(long long)mod))%mod+mod)%mod;
    }
};