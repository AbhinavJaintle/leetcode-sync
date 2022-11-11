class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        auto ip = unique(nums.begin(),nums.end());
        nums.resize(distance(nums.begin(),ip));
        if(nums.size()==1){
            return true;
        }
        int prev = nums[0];
        if(nums[1]>prev){
            for(int i = 1; i<nums.size(); i++){
                if(nums[i]<prev){
                    return false;
                }
                prev=nums[i];
            }
            return true;
        }
        if(nums[1]<prev){
            for(int i = 1; i<nums.size(); i++){
                if(nums[i]>prev){
                    return false;
                }
                prev=nums[i];
            }
            return true;
        }
        return true;
    }
};