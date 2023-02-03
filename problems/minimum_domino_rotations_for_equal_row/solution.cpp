class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        unordered_map<int,int> m1;
        unordered_map<int,int> m2;
        unordered_map<int,int> m3;

        for(int i = 0; i<tops.size(); i++){
            m1[tops[i]]++;
            m2[tops[i]]++;
            m3[bottoms[i]]++;
            if(bottoms[i]!=tops[i])m1[bottoms[i]]++;
        }
        int prev1=0;
        int prev2=0;

        for(auto&i:m1){
            if(i.second==tops.size()){
                prev1=max(prev1,m2[i.first]);
                prev2=max(prev2,m3[i.first]);
            }
        }
        if(prev1==0&&prev2==0)return -1;
        return min(tops.size()-prev1,bottoms.size()-prev2);
    }
};