class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        unordered_map<int,pair<int,int>> m;
        m[nums.size()-1]={nums[nums.size()-1],0};
        for(int i = nums.size()-2; i>=0; i--){
            m[i]={nums[i]+m[i+1].second,m[i+1].first};
        }
        int sum=0;
        int e = 0, o = 0;
        for(int i = 0; i<nums.size()-1; i++){
            if(i%2==0){
                if(e+m[i+1].first==o+m[i+1].second){
                    sum++;
                }
                e+=nums[i];
            }
            else{
                if(e+m[i+1].second==o+m[i+1].first){
                    sum++;
                }
                o+=nums[i];
            }
        }
        if(e==o)sum++;
        return sum;
    }
};