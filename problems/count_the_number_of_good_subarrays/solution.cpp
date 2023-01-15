class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long sum=0;
        unordered_map<int,int> m;
        int s = 0;
        int val = 0;
        for(int i = 0; i<nums.size(); i++){
            if(m[nums[i]]) val+=m[nums[i]];
            m[nums[i]]++;
            while(val>=k){
                sum+=nums.size()-i;
                val-=m[nums[s]]-1;
                m[nums[s]]--;
                s++;
            }
        }
        
        return sum;
    }
};