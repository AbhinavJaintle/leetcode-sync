class Solution {
public:        
    int jump(vector<int>& nums) {
        if(nums.size()==1){
            return 0;
        }
        vector<int> df(nums.size(),0);
        df[nums.size()-1]=0;
        df[nums.size()-2]=1;
        for(int i = nums.size()-3; i>-1; i--){
            int points = 10e+4;
            for(int j = 1; j<=nums[i]&&i+j<nums.size(); j++){
                points = min(df[i+j],points);
            }
            df[i] = 1+points;
        }
        return df[0];
    }
};