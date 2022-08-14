class Solution {
public:
    int edgeScore(vector<int>& edges) {
        map<int,long long int> m;
        for(int i = 0; i<edges.size(); i++){
            m[edges[i]]+=i;
        }
        int maxif=0;
        long long int maxis=0;
        for(auto i:m){
            if(i.second>maxis){
                maxis=i.second;
                maxif=i.first;
            }
        }
        return maxif;
    }
};