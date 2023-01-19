class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int sum1=0;
        int sum2=0;
        for(auto&i:nums1){
            sum1+=i;
        }
        for(auto&i:nums2){
            sum2+=i;
        }
        if(sum2>sum1){
            vector<int> temp=nums1;
            nums1=nums2;
            nums2=temp;
            int t = sum1;
            sum1=sum2;
            sum2=t;
        }
        
            sort(nums1.begin(),nums1.end(),greater<int>());
            sort(nums2.begin(),nums2.end());
            int i1=0;
            int i2=0;
            int ops=0;
            int diff=sum1-sum2;
            while(i1<nums1.size()&&i2<nums2.size()&&diff>0){
                if(nums1[i1]-1>6-nums2[i2]){
                    diff-=nums1[i1]-1;
                    i1++;
                    ops++;
                }
                else{
                    diff-=6-nums2[i2];
                    i2++;
                    ops++;
                }
            }
            if(diff<=0)return ops;
            else if(i1<nums1.size()){
                while(i1<nums1.size()&&diff>0){
                    ops++;
                    diff-=nums1[i1]-1;
                    i1++;
                }
            }
            else{
               while(i2<nums2.size()&&diff>0){
                    ops++;
                    diff-=6-nums2[i2];
                    i2++;
                } 
            }
            if(diff<=0)return ops;
        return -1;
    }
};