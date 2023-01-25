class Solution {
    unordered_map<int,int> vis;
public:
    void helper(int index, vector<int>& edges, vector<int>& n, int curr){
        vis[index]++;
        n[index]=curr;
        curr++;
        if(edges[index]!=-1){
            if(!vis[edges[index]]){
                helper(edges[index],edges,n,curr);
            }
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<int>n1(edges.size(),INT_MAX);
        vector<int>n2(edges.size(),INT_MAX);
        vis.clear();
        helper(node1,edges,n1,0);
        vis.clear();
        helper(node2,edges,n2,0);
        int maxi=INT_MAX;
        int index=-1;
        for(int i = 0; i<edges.size(); i++){
            if(max(n1[i],n2[i])<maxi){
                maxi=max(n1[i],n2[i]);
                index=i;
            }
        }
        return index;
    }
};