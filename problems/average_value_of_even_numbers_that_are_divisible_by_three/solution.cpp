class Solution {
public:
    int averageValue(vector<int>& nums) {
        int count = 0;
        int sum = 0;
        for(auto&i:nums){
            if(i%6==0){
                count++;
                sum+=i;
            }
        }
        if(count==0){
            return 0;
        }
        return sum/count;
    }
};