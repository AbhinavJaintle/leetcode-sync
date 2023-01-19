class Solution {
public:
    bool check(vector<int>& nums) {
        bool flag=true;
        int maxi=nums[0];
        for(int i = 0; i<nums.size(); i++){
            if(i<nums.size()-1&&nums[i+1]<nums[i]){
                if(flag){ 
                    flag=false;
                    continue;
                }
                else return false;
            }
            if(!flag){
                if(nums[i]>maxi)return false;
            }
        }
        return true;
    }
};