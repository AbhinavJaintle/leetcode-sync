class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = prices.size();
        int prev=prices[0];
        long long curr=1;
        for(int i = 1; i<prices.size(); i++){
            if(prev-prices[i]!=1){
                ans+=(curr*(curr-1))/2;
                prev=prices[i];
                curr=1;
            }
            else{
                curr++;
                prev=prices[i];
            }
        }
        ans+=(curr*(curr-1))/2;
        return ans;
    }
};