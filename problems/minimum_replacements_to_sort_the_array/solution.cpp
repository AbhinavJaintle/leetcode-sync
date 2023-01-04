class Solution {
public:
    
    long long minimumReplacement(vector<int>& nums) {
        long long sum=0;
        int curr=nums[nums.size()-1];
        for(int i = nums.size()-2; i>=0; i--){
            if(nums[i]>curr){
                int temp =((nums[i]-1)/curr)+1;
                sum+=temp-1;
                curr=nums[i]/temp;
            }
            else{
                curr=nums[i];
            }
        }    
        return sum;
    }
};