class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,vector<int>> m;
        int maxi = 1;
        for(int i = 0; i<nums.size(); i++){
            if(m[nums[i]].size()==0){
                m[nums[i]] = {1,i,i};
            }
            else{
                m[nums[i]][0]++;
                m[nums[i]][2] = i;
                maxi=max(maxi,m[nums[i]][0]);
            }
        }
        int mini = 60000;
        for(auto&i:m){
            if(i.second[0]==maxi){
                mini = min(mini,i.second[2]-i.second[1]+1);
            }
        }
        return mini;
    }
};