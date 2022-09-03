class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        map<int,int> m;
        for(int i = 0; i<nums.size()-1; i++){
            int temp = nums[i]+nums[i+1];
            if(m[temp]>0){
                return true;
            }
            m[temp]=1;
        }
        return false;
    }
};