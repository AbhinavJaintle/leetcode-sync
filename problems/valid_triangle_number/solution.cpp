class Solution {
public:
    int triangleNumber(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        int count = 0;
        
        for(int i = nums.size()-1; i>=2; i--){
            int b = 0;
            int e = i-1;
            while(b<e){
                if(nums[b]+nums[e]>nums[i]){
                    count+=e-b;
                    e--;
                }
                else{
                    b++;
                }
            }
        }
        return count;
    }
};