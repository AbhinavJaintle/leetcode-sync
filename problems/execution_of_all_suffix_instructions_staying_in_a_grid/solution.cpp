class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> v(s.length(),0);
        for(int i = 0; i<s.length(); i++){
            int s1=startPos[0];
            int s2=startPos[1];
            int res=-1;
            int index=i;
            while(s1>=0&&s1<n&&s2>=0&&s2<n&&index<s.length()){
                if(s[index]=='L')s2--;
                else if(s[index]=='R')s2++;
                else if(s[index]=='U')s1--;
                else s1++;
                res++;
                index++;
            }
            if(s1>=0&&s1<n&&s2>=0&&s2<n)res++;
            v[i]=res;
        }
        return v;
    }
};