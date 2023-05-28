class Solution {
public:
    long long minimumCost(string s) {
        vector<long long> l(s.length());
        vector<long long> r(s.length());
        char prev = '0';
        long long c = 0;
        vector<vector<int>> v(s.length(),vector<int>(2,-1));
        int z=-1;
        int o = -1;
        for(int i = 0; i<s.length(); i++){
            if(s[i]=='0'){z=i;v[i][0]=o;}
            else{o=i;v[i][0]=z;}
            if(s[i]==prev){
                c++;
                l[i]=c;
            }
            else{
                c+=i+1;
                l[i]=c;
            }
            prev=s[i];
        }
        prev='0';
        c=0;
        z=-1;
        o=-1;
        for(int i = s.length()-1; i>=0; i--){
            if(s[i]=='0'){z=i;v[i][1]=o;}
            else{o=i;v[i][1]=z;}
            if(s[i]==prev){
                c++;
                r[i]=c;
            }
            else{
                c+=s.length()-i;
                r[i]=c;
            }
            prev=s[i];
        }
        long long mini = LONG_MAX;
        for(int i = 0; i<s.length(); i++){
            int index1=v[i][0];
            int index2=v[i][1];
            long long ans=0;
            if(index1!=-1)ans+=l[index1];
            if(index2!=-1)ans+=r[index2];
            mini=min(mini,ans);
        }
        return mini;
    }
};