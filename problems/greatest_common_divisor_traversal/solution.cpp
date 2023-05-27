int primes[65] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 
    53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 
    137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 
    227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313};
class Solution {
public:
int find(int i, vector<int> &ds) {
    return ds[i] < 0 ? i : ds[i] = find(ds[i], ds);
}
bool canTraverseAllPairs(vector<int>& nums) {
    vector<int> ds(nums.size(), -1);
    unordered_map<int, int> p_i;
    for (int i = 0; i < nums.size(); ++i) {
        vector<int> facts;
        for (int p : primes)
            if (nums[i] % p == 0) {
                facts.push_back(p);
                while(nums[i] % p == 0)
                    nums[i] /= p;
            }
        if (nums[i] != 1)
            facts.push_back(nums[i]);
        for (int f : facts) {
            if (p_i.count(f)) {
                int pi = find(i, ds), pj = find(p_i[f], ds);
                if (pi != pj) {
                    if (ds[pi] > ds[pj])
                        swap(pi, pj);
                    ds[pi] += ds[pj];
                    ds[pj] = pi;
                }                
            }
            else
                p_i[f] = i;
        }
    }
    return abs(*min_element(begin(ds), end(ds))) == nums.size();
}
};