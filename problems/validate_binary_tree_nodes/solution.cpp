class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        int nodecnt=0;
        int edgecnt=0;
        vector<vector<int>> adjL(n);
        vector<int> indegree(n,0);
        vector<bool> visited(n,false);
        
        //adj list
        for(int i=0;i<n;i++){
            if(leftChild[i]!=-1){
                adjL[i].push_back(leftChild[i]);
                indegree[leftChild[i]]++;
                edgecnt++;
            }
            if(rightChild[i]!=-1){
                adjL[i].push_back(rightChild[i]);
                indegree[rightChild[i]]++;
                edgecnt++;
            }
           
        }
        
        queue<int> q;
        
        //check indegree
        for(int i=0;i<n;i++){
            if(indegree[i]>1)
                return false;
            if(indegree[i]==0)
                q.push(i);
        }
        
        //toposort to keep node count
        while(!q.empty()){
            int temp=q.front();
            q.pop();
            visited[temp]=true;
            nodecnt++;
            for(auto &child:adjL[temp]){
                if(!visited[child] && indegree[child]==1)
                    q.push(child);
                
            }
        }
        
        if(nodecnt!=n || edgecnt!=n-1)
            return false;
        return true;
    }
};