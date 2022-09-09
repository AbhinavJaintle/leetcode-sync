class Solution {
public:
    string reverseWords(string s) {
        int count = 0;
        stack<int> st;
        string y;
        int flag = 0;
        for(int i = 0; i<s.length(); i++){
            if(i==0&&s[i]==' '){
                flag=1;
                continue;
            }
            if(flag==1&&s[i]==' '){
                continue;
            }
            if(s[i]==' '){
                flag=1;
                y.push_back(s[i]);
                continue;
            }
            flag = 0;
            y.push_back(s[i]);
        }
        int t = y.length()-1;
        while(y[t]==' '){
            y.pop_back();
            t--;
        }
        for(int i = 0; i<y.length(); i++){
            if(y[i]==' '){
                if(count!=0) st.push(count);
                count = 0;
            }
            else{
                count++;
            }
        }
        if(count!=0){
            st.push(count);
        }
        reverse(y.begin(),y.end());
        int i = 0;
        while(i<y.length()&&!st.empty()){
            if(y[i]==' '){
                i++;
                continue;
            }
            int temp = st.top();
            st.pop();
            reverse(y.begin()+i,y.begin()+i+temp);
            i+=temp;
        }
        return y;
    }
};