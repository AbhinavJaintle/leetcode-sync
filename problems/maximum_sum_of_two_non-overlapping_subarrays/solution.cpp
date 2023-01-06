class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int prev=0;
        for(auto&i:nums){
            i+=prev;
            prev=i;
        }
        int maxi=0;
        for(int i = 0; i<nums.size()-firstLen+1; i++){
            int temp = i==0?nums[i+firstLen-1]:nums[i+firstLen-1]-nums[i-1];
            int t =0;
            for(int j = 0; j<nums.size()-secondLen+1; j++){
                if(j+secondLen-1<i||j>i+firstLen-1){
                    int k = j==0?nums[j+secondLen-1]:nums[j+secondLen-1]-nums[j-1];
                    t=max(t,k);
                }
            }
            maxi=max(maxi,temp+t);
        }
        return maxi;
    }
};