class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> v;
        bool flag=true;
        for(auto&i:intervals){
            if(flag&&newInterval[1]<i[0]){
                v.push_back(newInterval);
                v.push_back(i);
                flag=false;
            }
            else if(flag&&newInterval[0]<=i[1]){
                newInterval={min(newInterval[0],i[0]),max(i[1],newInterval[1])};
            }
            else{
                v.push_back(i);
            }
        }
        if(flag) v.push_back(newInterval);
        return v;
    }
};