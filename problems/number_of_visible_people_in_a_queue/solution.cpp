class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n=heights.size();
        vector<int> ans(n,0);
        stack<pair<int,int>> st; // height && index in array
        for(int i=0;i<n;i++){
            int height=heights[i];
            while(!st.empty() && st.top().first<height){
                int prev=st.top().second;
                ans[prev]++;
                st.pop();
            }
            if(!st.empty())
                ans[st.top().second]++;
            st.push({height,i});
                
        }
        return ans;
    }
};