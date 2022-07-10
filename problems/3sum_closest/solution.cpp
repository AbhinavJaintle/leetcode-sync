class Solution {
public:
int threeSumClosest(vector<int> nums, int target){
    int diff = INT_MAX;
    int ans = 0;
    sort(nums.begin(),nums.end());
    for(int i =0; i<nums.size();i++){
        int l = i+1;
        int r = nums.size()-1;
        while(l<r){
            if(nums[i]+nums[r]+nums[l]==target){
                return target;
            }else if(abs(nums[i]+nums[r]+nums[l]-target)<diff){
                diff = abs(nums[i]+nums[r]+nums[l]-target);
                ans = nums[i]+nums[r]+nums[l];
            }
            if(nums[i]+nums[r]+nums[l]<target){
                l++;
            }
            else{
                r--;
            }
        }
        
    }
    return ans;
} 
};