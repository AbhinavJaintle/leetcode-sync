
// Let us assume that target represents height of columns on a square grid. One operation corresponds to laying out continuous row of bricks. What is the number of these rows? To find this number we count the number of left edges of these rows.

// Example: [3,1,5,4,2,3,4,2]. Left edges are marked by red color. Total number of left edges is 3 + 4 + 1 + 1.
// image

// Applying this approach we get

class Solution {
public:
    int minNumberOperations(vector<int>& A) {
        int res = 0, pre = 0;
        for (int a: A) {
            res += max(a - pre, 0);
            pre = a;
        }
        return res;
    }
};