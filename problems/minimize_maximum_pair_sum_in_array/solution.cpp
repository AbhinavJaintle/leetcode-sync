class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int maxi = 0;
        sort(nums.begin(),nums.end());
        int start = 0;
        int end = nums.size()-1;
        while(start<end){
            maxi=max(maxi, nums[start]+nums[end]);
            start++;
            end--;
        }
        return maxi;
    }
};