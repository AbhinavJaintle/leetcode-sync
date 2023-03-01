class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int prev=0;
        for(auto&i:arr){
            i^=prev;
            prev=i;
        }
        vector<int> v;
        for(auto&i:queries){
            if(i[0]==0)v.push_back(arr[i[1]]);
            else v.push_back(arr[i[1]]^arr[i[0]-1]);
        }
        return v;
    }
};