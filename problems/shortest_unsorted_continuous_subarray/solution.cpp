class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> v=nums;
        sort(v.begin(),v.end());
        int left=v.size();
        for(int i = 0; i<v.size(); i++){
            if(v[i]!=nums[i]){
                left=i;
                break;
            }
        }
        int right=-1;
        for(int i = v.size()-1; i>=0; i--){
            if(v[i]!=nums[i]){
                right=i;
                break;
            }
        }
        if(right<left)return 0;
        return right-left+1;
    }
};