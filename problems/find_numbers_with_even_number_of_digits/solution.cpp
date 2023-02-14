class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int sum=0;
        for(auto&i:nums){
            if(((int)log10(i))%2!=0)sum++;
        }
        return sum;
    }
};