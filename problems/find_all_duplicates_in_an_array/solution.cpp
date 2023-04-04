class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto&i:nums){
            m[i]++;
        }
        vector<int> v;
        for(auto&i:m){
            if(i.second==2){
                v.push_back(i.first);
            }
        }
        return v;
    }
};