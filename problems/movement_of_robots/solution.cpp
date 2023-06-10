class Solution {
public:
    int sumDistance(vector<int>& nums, string s, int d) {
        vector<long long> v(nums.size());
        for(int i = 0; i<nums.size(); i++){
            long long temp = s[i]=='R'? nums[i]+d:nums[i]-d;
            v[i]=temp;
        }
        sort(v.begin(),v.end());
        long long ans = 0;
        long long prev=0;
        for(int i = v.size()-2; i>=0; i--){
            ans = (ans + (((v[i+1]-v[i])%1000000007)*(v.size()-1-i)%1000000007)+prev)%1000000007;
            prev =  ((((v[i+1]-v[i])%1000000007)*(v.size()-1-i)%1000000007)+prev)%1000000007;
        }
        return ans;
    }
};