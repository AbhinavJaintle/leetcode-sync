class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        int mini = INT_MAX;
        vector<vector<pair<int,int>>> v(n+1);
        for(auto&i:roads){
            v[i[0]].push_back({i[1],i[2]});
            v[i[1]].push_back({i[0],i[2]});
        }
        unordered_map<int,int> m;
        queue<pair<int,int>> q;
        q.push({1,INT_MAX});
        while(!q.empty()){
            auto temp=q.front();
            q.pop();
            mini=min(mini,temp.second);
            m[temp.first]++;
            for(auto&i:v[temp.first]){
                if(!m[i.first]){
                    q.push(i);
                }
            }
        }
        return mini;
    }
};