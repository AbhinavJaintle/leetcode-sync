class Solution {
    int MOD = 1e9+7;
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        int prev = 0;
        vector<int> v;
        for(auto&i:nums){
            prev = (prev+i)%MOD;
            i=prev;
            v.push_back(i);
        }
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                v.push_back(nums[j]-nums[i]);
            }
        }
        sort(v.begin(),v.end());
        int sum = 0;
        for(int i = left-1; i<right; i++){
            sum = (sum+v[i])%MOD;
        }
        return sum;
    }
};