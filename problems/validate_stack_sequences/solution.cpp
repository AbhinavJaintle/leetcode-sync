class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int popIndex=0;
        int pushIndex=1;
        stack<int> st;
        st.push(pushed[0]);
        while(popIndex<popped.size()){
            while(pushIndex<pushed.size()&&(st.empty()||st.top()!=popped[popIndex])){
                st.push(pushed[pushIndex++]);
            }
            if(!st.empty()&&st.top()!=popped[popIndex++])return false;
            st.pop();
        }
        return true;
    }
};