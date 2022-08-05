class Solution {
public:
    
    int minPath(int index, int elem, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        if(index>triangle.size()-1||elem>triangle[triangle.size()-1].size()-1){
            return 0;
        }
        if(dp[index][elem]!=-1){
            return dp[index][elem];
        }   
        int temp = min(minPath(index+1, elem+1, triangle,dp), minPath(index+1, elem, triangle,dp));
        int ans = triangle[index][elem] + temp;
        return dp[index][elem]=ans;
    }
    
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(),vector<int>(triangle[triangle.size()-1].size(),-1));
        for(int i = 0; i<dp[0].size(); i++){
            dp[dp.size()-1][i] = triangle[triangle.size()-1][i];
        }
        return minPath(0,0,triangle,dp);
    }
};