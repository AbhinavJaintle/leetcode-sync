class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succprob, int start, int end) {
        
        vector<double>maxprobability(n,0.0);
        
        vector<vector<pair<int,double>>>adj(n);
        for(int i=0;i<edges.size();i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],succprob[i]});
            adj[edges[i][1]].push_back({edges[i][0],succprob[i]});
            
        }
        

        
        queue<pair<int,double>>q;
        q.push({start,1.0});
        maxprobability[start]=1;
      
        while(q.size()!=0)
        {
            pair<int,double>top=q.front();
            
            int v=top.first;
            double p=top.second;
            q.pop();
            
            for(int i=0;i<adj[v].size();i++)
            {
                int nextvertex=adj[v][i].first;
                double prob=adj[v][i].second;
                
                double maxp=p*prob;
                if(maxprobability[nextvertex]<maxp)
                {
                    maxprobability[nextvertex]=maxp;
                    q.push({nextvertex, maxprobability[nextvertex]});
                    
                }
                
                
            }
            
            
            
            
        }
        return maxprobability[end];
    }
};