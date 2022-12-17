class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        vector<int> maxi(nums.size());
        vector<int> mini(nums.size());
        int temp = 0;
        for(int i = 0; i<nums.size(); i++){
            temp=max(temp,nums[i]);
            maxi[i]=temp;
        }
        temp = 1e6;
        for(int i = nums.size()-1; i>=0; i--){
            temp=min(temp,nums[i]);
            mini[i]=temp;
        }
        int sum =0;
        for(int i = 1; i<nums.size()-1; i++){
            if(maxi[i-1]<nums[i]&&nums[i]<mini[i+1]){
                sum+=2;
            }
            else if(nums[i-1]<nums[i]&&nums[i]<nums[i+1]){
                sum+=1;
            }
        }
        return sum;
    }
};