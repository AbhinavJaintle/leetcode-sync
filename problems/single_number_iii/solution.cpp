class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xxory = 0;
        for(auto el: nums){
            xxory = xxory ^ el;
        }
        long long rsb = xxory & -xxory;
        int x = 0;
        int y = 0;
        for(auto el: nums){
            if((el & rsb) == 0){
                x = x ^ el;
            }else{
                y = y ^ el;
            }
        }
        return {x, y};
    }
};