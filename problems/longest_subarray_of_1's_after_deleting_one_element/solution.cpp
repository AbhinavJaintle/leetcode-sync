class Solution {
public:
    int longest(vector<int>& nums, int index, int maxi, int curr, int flag){
        if(index>=nums.size()){
            return maxi;
        }
        int ans = 0;
        if(flag==1){
            if(nums[index]==1){
                ans = longest(nums,index+1,max(maxi,curr+1),curr+1,1);
            }
            else{
                ans = longest(nums,index+1,maxi,0,1);
            }
        }
        else{
            if(nums[index]==1){
                ans = longest(nums,index+1,max(maxi,curr+1),curr+1,0);
            }
            else{
                ans = max(longest(nums,index+1,maxi,0,0),longest(nums,index+1,maxi,curr,1));
            }
        }
        return ans;
    }
    int longestSubarray(vector<int>& nums) {
        if(*min_element(nums.begin(),nums.end())==1){
            return nums.size()-1;
        }
        return longest(nums,0,0,0,0);
    }
};