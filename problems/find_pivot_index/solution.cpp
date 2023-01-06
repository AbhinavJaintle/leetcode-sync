class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int prev=0;
        for(auto&i:nums){
            i+=prev;
            prev=i;
        }
        int left=0;
        for(int i = 0; i<nums.size(); i++){
            int right = nums[nums.size()-1]-nums[i];
            if(left==right) return i;
            left=nums[i];
        }
        return -1;
    }
};