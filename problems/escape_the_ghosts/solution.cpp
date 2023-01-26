class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int temp = abs(target[0])+abs(target[1]);
        int mini=INT_MAX;
        for(auto&i:ghosts){
            int t = abs(target[0]-i[0])+abs(target[1]-i[1]);
            mini=min(mini,t);
        }
        return temp<mini;
    }
};