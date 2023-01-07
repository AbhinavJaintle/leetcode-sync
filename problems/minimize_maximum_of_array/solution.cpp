class Solution {
public:
        int minimizeArrayValue(vector<int>& A) {
        long sum = 0, res = 0;
        for (int i = 0; i < A.size(); ++i) {
            sum += A[i];
            long temp = ceil((double)sum / (i + 1));
            res = max(res, temp);
        }
        return res;
    }
};