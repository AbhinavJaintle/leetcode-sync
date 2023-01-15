class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int t1=0;
        int t2=0;
        for(auto&i:nums){
            t1+=i;
            string temp=to_string(i);
            for(auto&j:temp){
                t2+=j-'0';
            }
        }
        return abs(t1-t2);
    }
};