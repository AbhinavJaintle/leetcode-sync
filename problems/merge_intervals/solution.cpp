class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(begin(intervals), end(intervals));
        vector<vector<int>> ans {intervals[0]};                        // adding 1st interval to avoid checking ans.empty() each time in loop
        for(auto i : intervals)
            if(i[0] <= ans.back()[1])                          // merge intervals if they overlap
                ans.back()[1] = max(ans.back()[1], i[1]);
            else                                               // else insert new interval
                ans.push_back(i);
        return ans;
    }
};