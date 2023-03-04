class Solution {
public:
    long long coloredCells(int n) {
        long long temp=n;
        long long ans = 1+(temp-1)*(8+(temp-2)*4)/2;
        return ans;
    }
};