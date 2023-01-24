class Solution {
public:
    int minimumEffort(vector<vector<int>>& A) {
        int res = 0;
        for (auto &a : A)
            a[0] = a[1] - a[0];
        sort(A.begin(), A.end());
        for (auto &a : A)
            res = max(res + a[1] - a[0], a[1]);
        return res;
    }
};