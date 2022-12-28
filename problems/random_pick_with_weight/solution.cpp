class Solution {
public:
    vector<int> ps;
    Solution(vector<int> w) {
        partial_sum(w.begin(),w.end(),back_inserter(ps));
        srand(time(NULL));
    }
    
    int pickIndex() {
        int r = rand() %  ps.back();
        auto ub = upper_bound(ps.begin(),ps.end(),r);
        return distance(ps.begin(),ub);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */