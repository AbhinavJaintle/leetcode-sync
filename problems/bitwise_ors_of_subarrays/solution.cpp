class Solution {
public:
    int subarrayBitwiseORs(vector<int> A) {
        unordered_set<int> res, cur, cur2;
        for (int i: A) {
            cur2 = {i};
            for (int j: cur) cur2.insert(i|j);
            for (int j: cur = cur2) res.insert(j);
        }
        return res.size();
    }
};
// tc = o(30n)
//Suppose curr = {B[0][j], B[1][j], ..B[j][j]},
// B[0][j] has k0 set bits, B[1][j] has k1 set bits,... B[j][j] has kj set bits,
// each time B[i][j] -> B[i + 1][j] either keep same set bits or lose some set bits,

// B[0][j]   = 1111
// B[1][j]   = 1111
// B[2][j]   = 1011
// .
// .
// B[j-2][j] = 1001
// B[j-1][j] = 0001
// B[j][j]   = 0001

// so k0 <= k1 ...<= kj

// Since number of k0's set bits is up to 30, the process of B[0][j] to B[j][j] drops up to 30 bits, each drop(might lose more than one set bits) creates different number , that results in |curr| = |{B[0][j], B[1][j], ..B[j][j]}| up to 30 elements.