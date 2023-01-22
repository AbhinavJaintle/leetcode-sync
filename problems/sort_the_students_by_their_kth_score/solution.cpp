class Solution {
public:
    
    vector<vector<int>> sortTheStudents(vector<vector<int>>& score, int k) {
        unordered_map<int,vector<int>> m;
        vector<int> v;
        for(int i = 0; i<score.size(); i++){
            v.push_back(score[i][k]);
            m[score[i][k]]=score[i];
        }
        sort(v.begin(),v.end(),greater<int>());
        for(int i = 0; i<score.size(); i++){
            score[i]=m[v[i]];
        }
        return score;
    }
};