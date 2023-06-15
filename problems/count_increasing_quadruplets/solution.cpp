class Solution {
public:
    long long countQuadruplets(vector<int>& nums) {
        vector<vector<int>> v(nums.size(),vector<int>(nums.size()));
        for(int i = 0; i<nums.size(); i++){
            int curr = 0;
            for(int j = i-1; j>=0; j--){
                if(nums[j]<nums[i]){
                    curr++;
                }
                v[i][j]=curr;
            }
            curr=0;
            for(int j = i+1; j<nums.size(); j++){
                if(nums[j]>nums[i]){
                    curr++;
                }
                v[i][j]=curr;
            }
        }
        long long count = 0;
        for(int i = 1; i<nums.size()-1; i++){
            for(int j = i+1; j<nums.size(); j++){
                if(nums[j]<nums[i]){
                    count+=(v[i][nums.size()-1]-v[i][j])*(v[j][0]-v[j][i]);
                }
            }
        }
        return count;
    }
};