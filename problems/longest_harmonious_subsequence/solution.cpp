class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        int maxi=0;
        for(int i = 0; i<nums.size(); i++){
            int temp=1;
            int index=i+1;
            while(index<nums.size()&&nums[index]>=nums[i]-1){
                temp++;
                index++;
            }
            if(nums[i]-nums[index-1]==1) maxi=max(maxi,temp);
        }
        return maxi;
    }
};