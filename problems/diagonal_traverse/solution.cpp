class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> v;
        int row = 0;
        int col=0;
        bool dir = true;
        int sz = mat.size()*mat[0].size();
        while(v.size()!=sz){
            while((dir&&row!=0&&col!=mat[0].size()-1)||(!dir&&row!=mat.size()-1&&col!=0)){
                v.push_back(mat[row][col]);
                if(dir){
                    row--;
                    col++;
                }
                else{
                    row++;
                    col--;
                }
            }
            v.push_back(mat[row][col]);
            if(dir){
                if(col!=mat[0].size()-1)col++;
                else row++;
            }
            else{
                if(row!=mat.size()-1)row++;
                else col++;
            }
            dir=!dir;
        }
        return v;
    }
};