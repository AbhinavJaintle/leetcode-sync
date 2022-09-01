class Solution {
public:
    typedef pair<int, int> p;
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) //source = 0, dijkstra's algo
    {
        vector<int> red[n], blue[n];  //adjacency matrix
        
        for(auto r: redEdges)
            red[r[0]].push_back(r[1]);
        for(auto b: blueEdges)
            blue[b[0]].push_back(b[1]);
        
        vector<p> dist(n, {INT_MAX, INT_MAX}); //min dist with end edge = R, min dist with end edge = blue
        queue<p> q;
        int size, v, clr;
        
        dist[0] = {0,0};
        q.push({0,0});  //parent node, last edge color = R
        q.push({0,1});  //parent node, last edge color = B
        
        while(!q.empty())
        {
            size = q.size();
            while(size--)
            {
                v = q.front().first;
                clr = q.front().second;
                q.pop();
                
                if(clr == 0)  //red hai toh next blue edges pe jayenge
                {
                    for(auto u: blue[v])  //search for u connected to v with a blue edge
                    {
                        if(dist[u].second == INT_MAX)  //if dist of u is not yet visited with ending edge as blue
                        {
                            dist[u].second = dist[v].first + 1; //dist of u with blue ending edge = dist of it's parent with red ending edge b/c its alternate
                            q.push({u, 1});  //push the current node with info of the color of its last edge
                        }
                    }
                }
                else        //blue hai toh next red edges pe jayenge
                {
                    for(auto u: red[v])  //search for u connected to v with a red edge
                    {
                        if(dist[u].first == INT_MAX) //if dist of u is not yet visited with ending edge as red
                        {
                            dist[u].first = dist[v].second + 1; //dist of u with red ending edge = dist of it's parent with blue ending edge b/c its alternate
                            q.push({u, 0}); //push the current node with info of the color of its last edge
                        }
                    }
                }
            }
        }
        
        vector<int> ans;
        int mini;
        
        for(int i=0; i<n; i++)
        {
            mini = min(dist[i].first, dist[i].second);
            if(mini == INT_MAX)   //the node has no alternate colored path from 0
                ans.push_back(-1);
            else
                ans.push_back(mini);
        }
        return ans;
    }
};