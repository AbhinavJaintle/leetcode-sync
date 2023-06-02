class Solution {
public:
    int minAreaRect(vector<vector<int>>& points) {
        map<pair<int,int>,int> m;
        for(auto&i:points){
            m[{i[0],i[1]}]++;
        }
        int mini = INT_MAX;
        for(int i = 0; i<points.size(); i++){
            int lim = -1;
            for(int j = 0; j<points.size(); j++){
                if(points[j][0]==points[i][0]||points[j][1]==points[i][1]||(lim!=-1&&abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1])>lim))continue;
                if(m[{points[j][0],points[i][1]}]&&m[{points[i][0],points[j][1]}]){
                    mini = min(mini,abs(points[i][0]-points[j][0])*abs(points[i][1]-points[j][1]));
                    lim = abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);
                }
            }
        }
        return mini==INT_MAX?0:mini;
    }
};