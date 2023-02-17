class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> v;
        for(auto&i:queries){
            int sum=0;
            for(auto&j:points){
                int temp = pow((j[0]-i[0]),2)+pow((j[1]-i[1]),2);
                if(temp<=pow(i[2],2)){
                    sum++;
                }
            }
            v.push_back(sum);
        }
        return v;
    }
};