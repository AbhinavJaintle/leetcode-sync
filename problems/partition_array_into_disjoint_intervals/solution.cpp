class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        vector<int> mini(nums.size());
        vector<int> maxi(nums.size());
        int currmin = 1e+8;
        int currmax = -1*(1e+8);
        for(int i = 0; i<nums.size(); i++){
            currmax = max(nums[i],currmax);
            maxi[i] = currmax;
        }
        for(int i = nums.size()-1; i>=0; i--){
            currmin = min(nums[i],currmin);
            mini[i] = currmin;
        }
        for(int i = 0; i<nums.size()-1; i++){
            if(maxi[i]<=mini[i+1]){
                return i+1;
            }
        }
        return -1;
    }
};