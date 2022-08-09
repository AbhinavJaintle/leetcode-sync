class Solution {
public:
    
    double solve(vector<int>& nums, int i, int k, vector<int>& prefixSum, vector<vector<double>>& memo){
        if(i == nums.size()){
            return 0;
        }
        if(k == 1){
            return (prefixSum[nums.size()]-prefixSum[i])/((double)(nums.size()-i));
        }
        if(memo[i][k] != -1){
            return memo[i][k];
        }
        
        double result = 0;        
        
        // we can choose to do the partition anywhere between i and n
        for(int j=i+1; j<=nums.size(); j++){
            result = max(result, (prefixSum[j]-prefixSum[i])/((double)(j-i)) + solve(nums, j, k-1, prefixSum, memo));
        }
        
        return memo[i][k] = result;
    }
    
    double largestSumOfAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> prefixSum(n+1, 0);
        vector<vector<double>> memo(n, vector<double>(k+1, -1));
        
        // calculate the prefix sum array so that we can calculate the sum of any subarray in O(1) time
        for(int i=1; i<=n; i++){
            prefixSum[i] = prefixSum[i-1] + nums[i-1];
        }        
        
        // solve recursively and optimize via memoization
        return solve(nums, 0, k, prefixSum, memo);
    }
};