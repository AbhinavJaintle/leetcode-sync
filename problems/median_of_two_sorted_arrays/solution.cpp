class Solution {
public:
    double findMedianSortedArrays(vector<int> nums1, vector<int> nums2) {
        if(nums1.size()>nums2.size()){
            return findMedianSortedArrays(nums2,nums1);
        }
        int start = 0;
        int end = nums1.size();
        int partitionx;
        int partitiony;
        while(start<=end){
            partitionx=(start+end)/2;
            partitiony=(nums1.size()+nums2.size()+1)/2-partitionx;
            int leftx=partitionx==0?INT_MIN:nums1[partitionx-1];
            int rightx=partitiony==0?INT_MIN:nums2[partitiony-1];

            int lefty=partitionx==nums1.size()?INT_MAX:nums1[partitionx];
            int righty=partitiony==nums2.size()?INT_MAX:nums2[partitiony];

            if(leftx<=righty&&rightx<=lefty){
                if((nums1.size()+nums2.size())%2==0){
                    return (double) (max(leftx,rightx)+min(lefty,righty))/2;
                }
                else{
                    return (double) (max(leftx,rightx));
                }
            }
            else if(leftx>righty){
                end=partitionx-1;
            }
            else{
                start=partitionx+1;
            }
        }
        return -1;
    }
};