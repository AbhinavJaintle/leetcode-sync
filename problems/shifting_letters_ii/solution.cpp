class Solution {
public:
   string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n=s.size();
        vector<int> vec(n+1,0);
        // to fill vec
        for(auto &v: shifts){
            if(v[2]==1){
                vec[v[0]]+=1;
                vec[v[1]+1]-=1;
            } else{
                vec[v[0]]-=1;
                vec[v[1]+1]+=1;
            }
        }
        // prefix sum
        for(int i=1;i<=n;++i){
            vec[i]+=vec[i-1];
        }
        // shift character
        for(int i=0;i<n;++i){
            int val=((s[i]-'a')+vec[i])%26;
            if(val<0) val+=26;
            s[i]='a'+val;
        }
        return s;
    }
};