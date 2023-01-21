class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size())return getCommon(nums2,nums1);
        unordered_map<int,int> m;
        for(auto&i:nums1){
            m[i]++;
        }
        for(auto&j:nums2){
            if(m[j])return j;
        }
        return -1;
    }
};