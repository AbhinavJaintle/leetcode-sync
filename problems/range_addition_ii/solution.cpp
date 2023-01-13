class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int minix=m;
        int miniy=n;
        for(auto&i:ops){
            minix=min(minix,i[0]);
            miniy=min(miniy,i[1]);
        }
        return minix*miniy;
    }
};