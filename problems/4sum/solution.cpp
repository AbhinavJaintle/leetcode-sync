class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        set<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n=nums.size();
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                long long temp_target = target - (long long)(nums[i] + nums[j]);
                int left = j+1, right = n-1;
                while(left<right) {
                    int sum = nums[left] + nums[right];
                    if(sum > temp_target) right--;
                    else if(sum < temp_target) left++;
                    else {
                        res.insert({nums[i], nums[j], nums[left], nums[right]});
                        int last_left = nums[left], last_right = nums[right];
                        left++;
					    right--;
                    }
                }
            }
        }
        vector<vector<int>> ans(res.begin(), res.end());
        return ans;
    }
};