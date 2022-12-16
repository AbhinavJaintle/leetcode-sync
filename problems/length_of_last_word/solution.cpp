class Solution {
public:
    int lengthOfLastWord(string s) {
        string temp;
        stack<string> st;
        for(auto&i:s){
            if(i==' '){
                if(temp!=""){
                    st.push(temp);
                    temp="";
                }
            }
            else{
                temp.push_back(i);
            }
        }
        if(temp!=""){
            st.push(temp);
        }
        return st.top().length();
    }
};