class Solution {
public:
    long long appealSum(string s) {
        vector<int> last(26);
        long res = 0, n = s.size(), total = 0;
        for (int i = 0; i < n; ++i) {
            total += i + 1 - last[s[i] - 'a'];
            last[s[i] - 'a'] = i + 1;
            res += total;
        }
        return res;
    }
};