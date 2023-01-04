class Solution {
public:
    void sortColors(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto&i:nums){
            m[i]++;
        }
        for(auto&i:nums){
            if(m[0]){
                i=0;
                m[0]--;
            }
            else if(m[1]){
                i=1;
                m[1]--;
            }
            else{
                i=2;
                m[2]--;
            }
        }
    }
};