class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> right = nums;
        int prev=1;
        for(int i = nums.size()-1; i>=0; i--){
            right[i]*=prev;
            prev=right[i];
        }
        prev=1;
        for(int i = 0; i<nums.size(); i++){
            nums[i]*=prev;
            prev=nums[i];
        }        
        right[0]=right[1];
        for(int i = 1; i<nums.size()-1; i++){
            right[i]=nums[i-1]*right[i+1];
        }
        right[nums.size()-1]=nums[nums.size()-2];
        return right;
    }
};