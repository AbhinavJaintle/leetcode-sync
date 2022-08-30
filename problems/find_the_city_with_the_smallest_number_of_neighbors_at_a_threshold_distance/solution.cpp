class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& e, int d) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<e.size();i++){
            adj[e[i][0]].push_back(make_pair(e[i][1],e[i][2]));
            adj[e[i][1]].push_back(make_pair(e[i][0],e[i][2]));
        }
        vector<int>ans(n,-1);
        for(int i=0;i<n;i++){
            set<pair<int,int>>s;
            s.insert(make_pair(0,i));
            vector<int>dis(n,INT_MAX);
            dis[i]=0;
            while(!s.empty()){
                auto x=*(s.begin());
                s.erase(x);
                int u=x.second;
                int w=x.first;
                for(auto i:adj[u]){
                    if(w+i.second < dis[i.first]){
                        s.erase(make_pair(dis[i.first],i.first));
                        s.insert(make_pair(w+i.second,i.first));
                        dis[i.first]=w+i.second;
                    }
                }
            }
            int count=0;
            for(int j=0;j<n;j++){
                if(dis[j]<=d && j!=i)
                    count++;
            }
            ans[i]=count;
        }
        int min=INT_MAX;
        int result=-1;
        for(int i=0;i<n;i++){
            if(min>=ans[i] && ans[i]!=-1){
                min=ans[i];
                result=i;
            }
        }
        return result;
    }
};