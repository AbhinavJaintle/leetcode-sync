class Solution {
public:
    int semiOrderedPermutation(vector<int>& nums) {
        auto it1 = min_element(nums.begin(),nums.end());
        auto it2 = max_element(nums.begin(),nums.end());
        int ops1 = distance(nums.begin(),it1);
        int ops2 = distance(nums.begin(),it2);
        return ops2<ops1?ops1+nums.size()-ops2-1-1:ops1+nums.size()-ops2-1;
    }
};