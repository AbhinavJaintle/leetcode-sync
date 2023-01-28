class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int prev=0;
        for(auto&i:nums){
            i+=prev;
            prev=i;
        }
        unordered_map<int,int> m;
        int sum=0;
        for(auto&i:nums){
            int diff=i-goal;
            sum=diff==0?sum+1+m[diff]:sum+m[diff];
            m[i]++;
        }
        return sum;
    }
};