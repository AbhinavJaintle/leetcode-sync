class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1&&trust.size()==0){
            return 1;
        }
        map<int,int> m;
        map<int,int> tt;
        for(int i = 0; i<trust.size(); i++){
            m[trust[i][0]]+=1;
            tt[trust[i][1]]+=1;
        }
        for(auto& i: tt){
            if(i.second==n-1&&m[i.first]==0){
                return i.first;
            }
        }
        return -1;
    }
};