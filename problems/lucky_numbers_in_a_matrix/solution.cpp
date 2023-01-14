class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        unordered_map<int,int> m;
        for(int i = 0; i<matrix.size(); i++){
            auto temp = min_element(matrix[i].begin(),matrix[i].end());
            if(m[temp-matrix[i].begin()]){
                m[temp-matrix[i].begin()]=max(*temp,m[temp-matrix[i].begin()]);
            }
            else{
                m[temp-matrix[i].begin()]=*temp;
            }
        }
        for(int i = 0; i<matrix.size(); i++){
            for(int j = 0; j<matrix[0].size(); j++){
                if(m[j]<matrix[i][j]) m[j]=-1;
            }
        }
        vector<int> ans;
        for(auto&i:m) if(i.second!=-1) ans.push_back(i.second);
        return ans;
    }
};