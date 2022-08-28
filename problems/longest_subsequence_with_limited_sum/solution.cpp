class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans;
        sort(nums.begin(),nums.end());
        vector<int> pre(nums.size()+1,0);
        for(int i = 1; i<nums.size()+1; i++){
            pre[i]=pre[i-1]+nums[i-1];
        }
        for(auto&i:queries){
            int count = 1;
            while(count<pre.size()&&i>=pre[count]){
                count++;
            }
            ans.push_back(count-1);
        }
        return ans;
    }
};