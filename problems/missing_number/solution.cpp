class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int prev=0;
        for(auto&i:nums){
            prev^=i;
        }
        for(int i=0; i<nums.size()+1; i++){
            prev^=i;
        }
        return prev;
    }
};