class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        vector<int> l(nums.size());
        vector<int> r(nums.size());
        unordered_map<int,int> m;
        int curr=0;
        for(int i = 0; i<nums.size(); i++){
            if(!m[nums[i]])curr++;
            l[i]=curr;
            m[nums[i]]++;
        }
        m.clear();
        curr=0;
        for(int i = nums.size()-1; i>=0; i--){
            r[i]=curr;
            if(!m[nums[i]])curr++;
            m[nums[i]]++;
        }
        vector<int> ans(nums.size());
        for(int i = 0; i<nums.size();i++){
            ans[i]=l[i]-r[i];
        }
        return ans;
    }
};