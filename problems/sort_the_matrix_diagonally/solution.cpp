class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        map<string,priority_queue<int, vector<int>, greater<int> >> m;
        map<string,vector<int>> rem;
        for(int i = 0; i<mat.size(); i++){
            for(int j = 0; j<mat[0].size(); j++){
                int temp1= i;
                int temp2= j;
                while(temp1-1>=0||temp2-1>0){
                    temp1--;
                    temp2--;
                }
                m[to_string(temp1)+"->"+to_string(temp2)].push(mat[i][j]);
                rem[to_string(i)+"#"+to_string(j)].push_back(temp1);
                rem[to_string(i)+"#"+to_string(j)].push_back(temp2);
            }
        }
        for(int i = 0; i<mat.size(); i++){
            for(int j = 0; j<mat[0].size(); j++){
                mat[i][j] = m[to_string(rem[to_string(i)+"#"+to_string(j)][0])+"->"+to_string(rem[to_string(i)+"#"+to_string(j)][1])].top();
                m[to_string(rem[to_string(i)+"#"+to_string(j)][0])+"->"+to_string(rem[to_string(i)+"#"+to_string(j)][1])].pop();
            }
        }
        return mat;
    }
};