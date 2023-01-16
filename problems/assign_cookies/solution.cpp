class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        int sum=0, index=0;
        int i=0;
        while(index<s.size()&&i<g.size()){
            if(g[i]<=s[index]){
                i++;
                sum++;
            }
            index++;
        }
        return sum;
    }
};