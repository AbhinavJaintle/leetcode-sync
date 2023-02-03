class Solution {
    int mod = 1e9+7;
public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        int index=0;
        vector<int> v;
        while(n>=1){
            if(n%2==1){
                v.push_back(pow(2,index));
            }
            n/=2;
            index++;
        }
        vector<int> ans;
        for(auto&i:queries){
            long long temp=1;
            for(int j=i[0]; j<=i[1]; j++){
                temp=(temp%mod*v[j]%mod)%mod;
            }
            ans.push_back((int)temp);
        }
        return ans;
    }
};