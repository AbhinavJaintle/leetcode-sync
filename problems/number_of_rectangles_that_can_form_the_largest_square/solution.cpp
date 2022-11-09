class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        unordered_map<int,int> m;
        int maxLen = 0;
        for(auto&i:rectangles){
            maxLen = max(min(i[0],i[1]),maxLen);
            m[min(i[0],i[1])]++;
        }
        return m[maxLen];
    }
};