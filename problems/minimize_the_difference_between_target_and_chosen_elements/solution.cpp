class Solution {
public:
    int helper(int index, vector<vector<int>>& mat, int target, int curr, vector<vector<int>>& m){
        if(index==mat.size())return abs(curr-target);
        if(m[index][curr]!=-1)return m[index][curr];
        int sum = INT_MAX;
        for(auto&i:mat[index]){
            sum=min(sum,helper(index+1,mat,target,curr+i,m));
            if(sum==0){
                return m[index][curr]=sum;
            }
        }
        return m[index][curr]=sum;
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        vector<vector<int>> m (71,vector<int>(4901,-1));
        return helper(0,mat,target,0,m);
    }
};