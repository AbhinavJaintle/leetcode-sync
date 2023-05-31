class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        vector<vector<int>> v(rowSum.size(),vector<int>( colSum.size(),0));
        for(int i = 0; i<colSum.size()-1; i++){
            int count = colSum[i];
            for(int j = 0; j<v.size(); j++){
                if(count==0)break;
                v[j][i] = min(count,rowSum[j]);
                count-=v[j][i];
                rowSum[j]-=v[j][i];
            }
        }
        for(int j = 0; j<v.size(); j++){
            v[j][colSum.size()-1] = rowSum[j];
        }
        return v;
    }
};