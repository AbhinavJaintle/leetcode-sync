class Solution {
    long long mod = 1e9+7;
public:
    int helper(int index, int n, bool flag, map<pair<int,bool>,int>& m){
        if(index==n)return 1;
        if(m[{index,flag}])return m[{index,flag}];
        int num1=0;
        int num2=0;
        if(flag){
            num1 = (helper(index+1,n,false,m))%mod;
        }
        num2 = (num1+helper(index+1,n,true,m))%mod;
        return m[{index,flag}] = num2;
    }
    int countHousePlacements(int n) {
        map<pair<int,bool>,int> m;
        return (int)((helper(0,n,true,m)%mod*helper(0,n,true,m)%mod)%mod);
    }
};