class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        unordered_map<int, int> m;
        for(int i = 0; i<k; i++){
            m[nums[i]]++;
        }
        vector<int> v;
        int start=0;
        for(int i = k-1; i<nums.size(); i++){
            if(i!=k-1){
                m[nums[start]]--;
                m[nums[i]]++;
                start++;
            }
            int prev;
            int curr=0;
            for(int j = -50; j<0; j++){
                if(m[j]!=0)curr+=m[j];
                prev=j;
                if(curr>=x)break;
            }
            if(curr>=x){
                v.push_back(prev);
            }
            else v.push_back(0);
        }
        return v;
        
    }
};