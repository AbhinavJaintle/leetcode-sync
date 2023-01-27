class Solution {
public:
    int countElements(vector<int>& nums) {
      sort(nums.begin(),nums.end());
      int sum=0;
      for(auto&i:nums){
          if(i!=nums[0]&&i!=nums[nums.size()-1])sum++;
      }
      return sum;
    }
};