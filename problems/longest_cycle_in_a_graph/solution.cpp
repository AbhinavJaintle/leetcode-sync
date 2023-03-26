class Solution {
public:
    int longestCycle(vector<int>& edges) {
        unordered_map<int,int> m;
        int ans=-1;
        for(int i = 0; i<edges.size(); i++){
            if(!m[i]){
                unordered_map<int,int> m1;
                m[i]++;
                m1[i]++;
                stack<int> st;
                st.push(i);
                int curr=edges[i];
                while(curr!=-1){
                    if(m[curr]){
                        if(m1[curr]){
                            int temp=1;
                            while(st.top()!=curr){
                                temp++;
                                st.pop();
                            }
                            ans=max(ans,temp);
                        }
                        break;
                    }
                    else{
                        m[curr]++;
                        m1[curr]++;
                        st.push(curr);
                        curr=edges[curr];
                    }
                }
            }
        }
        return ans;
    }
};