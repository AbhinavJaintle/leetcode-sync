class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int index=0;
        int sum=0;
        if(nums.size()<3)return 0;
        while(index<nums.size()-2){
            int diff = nums[index+1]-nums[index];
            int temp=index;
            int i = index+2;
            while(i<nums.size()){
                if(nums[i]-nums[i-1]==diff){
                    sum+=i-index-1;
                    i++;
                }
                else{
                    index=i-1;
                    break;
                }
            }
            if(index==temp)break;
        }
        return sum;
    }
};