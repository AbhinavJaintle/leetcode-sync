class Solution {
public:
    static bool mysort(vector<int>& a, vector<int>& b){
        return a[1]==b[1]?a[0]<b[0]:a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        int count = 0, arrow = INT_MIN;
        sort(points.begin(), points.end(), mysort);
        for(int i = 0; i<points.size(); i++){
            if(arrow!=INT_MIN && points[i][0]<=arrow){continue;} //former arrow shot points[i] 
            arrow = points[i][1]; // new arrow shot the end of points[i]
            count++;
        }
        return count;
    }
};