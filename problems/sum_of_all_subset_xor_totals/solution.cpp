class Solution {
public:
    int findAllSubsetXor(int i, vector<int>& nums, int x) {
      if(i == nums.size()) return x;
      return findAllSubsetXor(i+1, nums, x ^ nums[i])+findAllSubsetXor(i+1, nums,x);
    }
    int subsetXORSum(vector<int>& nums) {
        return findAllSubsetXor(0,nums,0);
    }
};
