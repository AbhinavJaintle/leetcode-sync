class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto&i:nums){
            m[i]++;
        }
        int sum;
        vector<int> v;
        for(int i =1; i<INT_MAX; i*=2){
            if(!m[i]){
                return i;
            }
        }
        return sum*2;
        
    }
};