class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i =0; i<nums.size(); i++){
            pq.push({nums[i],i});
        }
        vector<vector<int>> v;
        vector<long long> ans(nums.size(),0);     
        while(!pq.empty()){
            int prev  = pq.top().first;
            vector<int> temp;
            while(!pq.empty()&&pq.top().first==prev){
                temp.push_back(pq.top().second);
                pq.pop();
            }
            v.push_back(temp);
        }
        int index=0;
        for(int i = 0; i<v.size(); i++){
            vector<long long> f(v[i].size(),0);
            vector<long long> b(v[i].size(),0);
            for(int j = 1; j<v[i].size(); j++){
                ans[v[i][0]]+=v[i][j]-v[i][0];
            }
            f[0]=ans[v[i][0]];
            for(int j = 1; j<v[i].size(); j++){
                f[j]=f[j-1]-(v[i].size()-j)*(v[i][j]-v[i][j-1]);
            }
            for(int j = v[i].size()-2; j>=0; j--){
                ans[v[i][v[i].size()-1]]+=v[i][v[i].size()-1]-v[i][j];
            }
            b[v[i].size()-1]=ans[v[i][v[i].size()-1]];
            for(int j = v[i].size()-2; j>=0; j--){
                b[j]=b[j+1]-(j+1)*(v[i][j+1]-v[i][j]);
            }
            for(int j = 0; j<v[i].size(); j++){
                ans[v[i][j]]=f[j]+b[j];
            }
            
        }
        return ans;
    }
};