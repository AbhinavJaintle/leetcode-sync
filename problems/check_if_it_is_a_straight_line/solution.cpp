class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates[0][0]==coordinates[1][0]){
            for(int i = 2; i<coordinates.size(); i++){
                if(coordinates[0][0]!=coordinates[i][0])return false;
            }
            return true;
        }
        float m = (float)(coordinates[0][1]-coordinates[1][1])/(coordinates[0][0]-coordinates[1][0]);
        for(int i = 2; i<coordinates.size(); i++){
            if(coordinates[0][0]==coordinates[i][0]||(float)(coordinates[0][1]-coordinates[i][1])/(coordinates[0][0]-coordinates[i][0])!=m){
                return false;
            }
        }
        return true;
    }
};