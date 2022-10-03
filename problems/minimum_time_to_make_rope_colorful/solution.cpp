class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        stack<pair<char,int>> st;
        st.emplace(colors[0],neededTime[0]);
        int ans = 0;
        for(int i = 1; i<colors.length(); i++){
            char temp = colors[i];
            if(st.top().first==temp){
                if(st.top().second<neededTime[i]){
                    ans+=st.top().second;
                    st.emplace(temp,neededTime[i]);
                }
                else{
                    ans+=neededTime[i];
                }
            }
            else{
                st.emplace(temp,neededTime[i]);
            }
        }
        return ans;
    }
};