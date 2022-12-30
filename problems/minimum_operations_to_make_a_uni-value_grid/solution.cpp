class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> v;
        for(auto&i:grid){
            for(auto&j:i){
                v.push_back(j);
            }
        }
        sort(v.begin(),v.end());
        int mid = v[v.size()/2];
        int sum = 0;
        for(auto&i:v){
            int temp = abs(i-mid);
            if(temp%x!=0){
                return -1;
            }
            sum+=temp/x;
        }
        return sum;
    }
};