
class RangeFreqQuery {
    unordered_map<int, vector<int>> m; // map from a value to all its indices
public:
    RangeFreqQuery(vector<int>& A) {
        for (int i = 0; i < A.size(); ++i) m[A[i]].push_back(i);
    }
    int query(int left, int right, int value) {
        if (m.count(value) == 0) return 0; // `value` doesn't exist in the original array
        auto &v = m[value]; // `v` is the array of all the indices of `value` in the original array
        int j = upper_bound(begin(v), end(v), right) - begin(v); // Find the first index `j` that `v[j] > right`.
        int i = lower_bound(begin(v), end(v), left) - begin(v); // Find the first index `i` that `v[i] >= left`.
        return j - i; // The answer is `j - i`
    }
};