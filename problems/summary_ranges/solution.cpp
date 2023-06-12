class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        if(!nums.size())return {};
        int curr = nums[0];
        int prev = nums[0];
        vector<string> v;
        for(int i = 1; i<nums.size(); i++){
            if(nums[i]!=prev+1){
                if(curr==prev){
                    v.push_back(to_string(curr));
                }
                else{
                    v.push_back(to_string(curr)+"->"+to_string(prev));
                }
                curr=nums[i];
                prev=nums[i];
            }
            else{
                prev=nums[i];
            }
        }
        if(curr==prev){
            v.push_back(to_string(curr));
        }
        else{
            v.push_back(to_string(curr)+"->"+to_string(prev));
        }
        return v;
    }
};