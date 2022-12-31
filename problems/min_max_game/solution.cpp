class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        vector<int> v;
        int flag=0;
        for(int i = 0; i<nums.size()-1; i+=2){
            if(flag==0){
                v.push_back(min(nums[i],nums[i+1]));
                flag=1;
            }
            else{
                v.push_back(max(nums[i],nums[i+1]));
                flag=0;
            }
        }
        return minMaxGame(v);
    }
};