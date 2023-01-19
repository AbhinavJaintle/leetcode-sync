class Solution {
public:
    int minOperations(vector<int>& nums) {
        int prev=0, sum=0;;
        for(auto&i:nums){
            if(i<=prev){
                sum+=prev-i+1;
                prev++;
            }
            else prev=i;
        }
        return sum;
    }
};