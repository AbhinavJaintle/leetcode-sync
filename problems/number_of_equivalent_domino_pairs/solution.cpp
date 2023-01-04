class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<vector<int>,int> m;
        int sum=0;
        for(auto&i:dominoes){
            if(m[i]){
                m[i]++;
            }
            else if(m[{i[1],i[0]}]){
                m[{i[1],i[0]}]++;
            }
            else{
                m[i]++;
            }
        }
        for(auto&i:m){
            sum+=i.second*(i.second-1)/2;
        }
        return sum;
    }
};