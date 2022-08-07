class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int ans = 0;
        for(int i = nums.size()-1; i>=0; i--){
            auto it1 = find(nums.begin(), nums.end(), nums[i]-2*diff);
            auto it2 = find(nums.begin(), nums.end(), nums[i]-diff);
            if(it1!=nums.end()&&it2!=nums.end()&&(it2>it1)&&(i>it2 - nums.begin())){
                ans+=1;
            }
        }
        return ans;
    }
};