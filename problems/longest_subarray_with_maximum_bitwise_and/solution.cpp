class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        int ans=0;
        int streak=0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]==maxi){
                streak++;
            }
            else{
                ans=max(ans,streak);
                streak=0;
            }
        }
        ans=max(ans,streak);
        return ans;
    }
};