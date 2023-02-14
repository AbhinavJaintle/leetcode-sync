class Solution {
public:
    int mod = 1e9+7;
    int numOfSubarrays(vector<int>& arr) {
        int prev=0;
        for(auto&i:arr){
            i+=prev;
            prev=i;
        }
        int e=0;
        int o=0;
        long long sum=0;
        for(auto&i:arr){
            if(i%2==0){
                sum=(sum+o+mod)%mod;
                e++;
            }
            else{
                sum=(sum+e+1+mod)%mod;
                o++;
            }
        }
        return (sum+mod)%mod;
    }
};