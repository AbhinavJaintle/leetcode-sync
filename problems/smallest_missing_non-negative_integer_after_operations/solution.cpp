class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int> m;
        for(auto&i:nums){
            if(i<0)i+=(value)*(abs(i)/value+1);
            m[i%value]++;
        }
        for(int i = 0; i<=nums.size(); i++){
            if(m[i]){
                m[i]--;
                continue;
            }
            else{
                if(m[i%value]){
                    m[i%value]--;
                    continue;
                }
                return i;
            }
        }
        return -1;
    }
};