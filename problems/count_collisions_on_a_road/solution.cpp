class Solution {
public:
    int countCollisions(string s) {
        int index=0;
        int ans=0;
        while(index<s.length()&&s[index]=='L')index++;
        stack<char>st;
        for(int i = index;i<s.length(); i++){
            if(s[i]=='R')st.push('R');
            else if(s[i]=='S'){
                while(!st.empty()){
                    if(st.top()!='R')break;
                    st.pop();
                    ans++;
                }
                st.push('S');
            }
            else{
                bool flag=true;
                while(!st.empty()){
                    if(flag){
                        if(st.top()=='R')ans+=2;
                        if(st.top()=='S')ans+=1;
                        flag=false;
                    }
                    else{ 
                        if(st.top()!='R')break;
                        ans+=1;
                    }
                    st.pop();
                }
                st.push('S');
            }
        }
        return ans;
    }
};