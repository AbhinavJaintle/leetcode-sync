class Solution {
public:
    int timeRequiredToBuy(vector<int>& target, int k) {
        int ans = 0;
        for (int i = 0; i < target.size(); ++i) {
            ans += min(target[k] - (i > k), target[i]);
        }
        return ans;
    }
};