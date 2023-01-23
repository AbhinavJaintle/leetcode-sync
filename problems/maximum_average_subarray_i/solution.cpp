class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int prev=0;
        for(auto&i:nums){
            i+=prev;
            prev=i;
        }
        double sum = -100000.00000;
        sum=max(sum,(double)nums[k-1]/k);
        for(int i = k; i<nums.size(); i++){
            sum=max(sum,(double)(nums[i]-nums[i-k])/k);
        }
        return sum;
    }
};