
class Solution {
public:
int minCostClimbingStairs(vector<int>& cost) {
int prev0 = cost[0], prev1 = cost[1];
for(int i = 2; i < (int)cost.size(); i++) {
int curr = min(prev0, prev1) + cost[i];
prev0 = prev1;
prev1 = curr;
} return min(prev0, prev1);
}
};