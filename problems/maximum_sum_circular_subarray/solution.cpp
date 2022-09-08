class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        if(*max_element(nums.begin(),nums.end())<0){
            return *max_element(nums.begin(),nums.end());
        }
        int maxi = nums[0];
        int curr= 0;
        int total=0;
        for(int i = 0; i<nums.size(); i++){
            total+=nums[i];
            curr+=nums[i];
            maxi = max(maxi,curr);
            if(curr<0) curr=0;
        }
        int mini = nums[0];
        curr= 0;
        for(int i = 0; i<nums.size(); i++){
            curr+=nums[i];
            mini = min(mini,curr);
            if(curr>0) curr=0;
        }
        return max(maxi,total-mini);
    }
};