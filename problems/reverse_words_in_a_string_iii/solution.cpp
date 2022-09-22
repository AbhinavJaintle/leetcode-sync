class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string temp;
        for(auto&i:s){
            if(i!=' '){
                temp.push_back(i);
            }
            else{
                st.push(temp);
                temp = "";
            }
        }
        st.push(temp);
        string cov;
        while(!st.empty()){
            cov+=st.top();
            cov+=" ";
            st.pop();
        }
        cov.pop_back();
        reverse(cov.begin(),cov.end());
        return cov;
    }
};