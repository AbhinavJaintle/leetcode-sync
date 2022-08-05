class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = 10e-4;
        int maxi = 10e-4;
        for(int i =prices.size()-1; i>=0;i--){
            maxi = max(maxi,prices[i]);
            mini = max(mini, maxi-prices[i]);
        }
        return mini;
    }
};