class Solution {
public:
    vector<int> twoSum(vector<int> nums, int target) {
        vector<int> sol(2);
        for(int i =0; i<nums.size(); i++){
            int one = nums[i];
            for(int j = i+1; j<nums.size(); j++){
                if(nums[j]+one==target){
                    sol[0]=i;
                    sol[1]=j;
                    return sol;
                }
            }
        }
        return sol;
    }
};