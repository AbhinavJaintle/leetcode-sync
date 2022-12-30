class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_map<int,int> m;
        int sum = 0;
        for(auto&i:nums){
            if(m[i]==0){
                sum++;
                m[i]++;
            }
            string temp = to_string(i);
            reverse(temp.begin(),temp.end());
            int t = stoi(temp);
            if(m[t]==0){
                sum++;
                m[t]++;
            }
        }
        return sum;
    }
};