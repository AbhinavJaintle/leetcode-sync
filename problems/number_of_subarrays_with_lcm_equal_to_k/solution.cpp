class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int sum=0;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]==k)sum++;
            int prev=nums[i];
            for(int j = i+1; j<nums.size(); j++){
                int temp=lcm(nums[j],prev);
                if(temp==k){
                    sum=sum+1;
                }
                else if(temp>k){
                    break;
                }
                prev=temp;
            }
        }
        return sum;
    }
};