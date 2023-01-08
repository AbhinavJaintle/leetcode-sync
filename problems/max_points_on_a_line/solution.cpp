class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int maxi=0;
        if(points.size()==1) return 1;
        for(int i = 0; i<points.size(); i++){
            unordered_map<int,int> vis;
            int x = points[i][0];
            int y = points[i][1];
            for(int j = i+1; j<points.size(); j++){
              if(vis[j]!=1){
                double m = (points[j][1]==y)?69696969:(double)(points[j][0]-x)/(points[j][1]-y);
                int sum=2;
                for(int k = j+1; k<points.size(); k++){
                    double temp = ((points[k][1]==y))?69696969:(double)(points[k][0]-x)/(points[k][1]-y);
                    if(temp == m){
                        vis[k]++;
                        sum++;
                    }
                }
                maxi=max(maxi,sum);
              }
            }
        }
        return maxi;
    }
};