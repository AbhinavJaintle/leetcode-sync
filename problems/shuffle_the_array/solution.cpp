class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans(2*n);
        for(int i = 0; i<nums.size()/2; i++){
            ans[2*i]=nums[i];
        }
        int start=1;
        for(int i = nums.size()/2; i<nums.size(); i++){
            ans[start]=nums[i];
            start+=2;
        }
        return ans;
    }
};