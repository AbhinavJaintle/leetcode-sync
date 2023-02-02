class Solution {
public:
    bool static mysort(pair<int,int> a, pair<int,int> b){
        return a.first==b.first?a.second<=b.second:a.first>b.first;
    }   
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> v;
        for(int i = 0; i<difficulty.size(); i++){
            v.emplace_back(profit[i],difficulty[i]);
        }
        sort(v.begin(),v.end(),mysort);
        int sum=0;
        for(auto&i:worker){
            for(auto&j:v){
                if(j.second<=i){
                    sum+=j.first;
                    break;
                }
            }
        }
        return sum;
    }
};