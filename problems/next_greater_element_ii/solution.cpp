class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> v(nums.size(),-1);
        stack<pair<int,int>> st;
        st.push({nums[0],0});
        for(int i = 1; i<nums.size(); i++){
            int curr = nums[i];
            while(!st.empty()&&curr>st.top().first){
                v[st.top().second]=curr;
                st.pop();
            }
            st.push({curr,i});
        }
        for(int i = 0; i<nums.size()-1&&!st.empty(); i++){
            int curr = nums[i];
            while(!st.empty()&&curr>st.top().first){
                v[st.top().second]=curr;
                st.pop();
            }
        }
        return v;
    }
};