class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        long long inc=0;
        long long dec=0;
        long long sum=0;
        for(int i = 0; i<nums1.size(); i++){
            if(nums1[i]==nums2[i]) continue;
            if(nums1[i]>nums2[i]){
                if(k==0)return -1;
                if((nums1[i]-nums2[i])%k!=0)return -1;
                inc+=(nums1[i]-nums2[i]);
            }
            else{
                if(k==0)return -1;
                if((nums2[i]-nums1[i])%k!=0)return -1;
                dec+=(nums2[i]-nums1[i]);
            }
        }
        if(k==0){
            return 0;
        }
        if(inc==dec)return inc/k;
        return -1;
    }
};