class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int ans = pow(2,maximumBit)-1;
        int prev=0;
        for(auto&i:nums){
            i^=prev;
            prev=i;
            cout<<i;
            i^=ans;
        }
        reverse(nums.begin(),nums.end());
        return nums;
    }
};