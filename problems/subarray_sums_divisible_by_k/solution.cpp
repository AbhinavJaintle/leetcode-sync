class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum=0, prev=0, curr=0;
        unordered_map<int,int> m;
        bool flag=true;
        for(auto&i:nums){
            i+=prev;
            prev=i;
            if(prev%k==0)sum++;
            sum+=m[((i)%k+k)%k];
            m[((i)%k+k)%k]++;
        }
        
        return sum;
    }
};