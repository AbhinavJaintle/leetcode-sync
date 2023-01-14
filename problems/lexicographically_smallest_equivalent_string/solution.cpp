class Solution {
    vector<int> par=vector<int>(26,-1);
public:
    int find(int n){
        if(par[n]==-1) return n;
        return par[n]=find(par[n]);
    }
    void Union(int n1, int n2){
        int t1 = find(n1);
        int t2 = find(n2);
        if(t1!=t2){
            par[max(t1,t2)]=min(t1,t2);
        }
    }
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        for(int i = 0; i<s1.length(); i++){
            Union(s1[i]-'a',s2[i]-'a');
        }
        for(auto&i:baseStr){
            i=find(i-'a')+'a';
        }
        return baseStr;
    }
};