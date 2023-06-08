class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int mini = INT_MAX;
        int curr=0;
        int prev=0;
        for(int i = 0; i<nums.size(); i++){
            curr+=nums[i];
            while(curr>=target){
                mini=min(mini,i-prev+1);
                curr-=nums[prev];
                prev++;
            }
        }
        return mini==INT_MAX?0:mini;
    }
};