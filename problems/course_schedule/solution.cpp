class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses,vector<int>{});
        vector<int> indegree(numCourses,0);
        for(vector<int>& pre:prerequisites){
            graph[pre[1]].push_back(pre[0]);
            indegree[pre[0]]++;
        }
        queue<int> start;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                start.push(i);
            }
        }
        while(!start.empty()){
            int s = start.front();
            start.pop();
            for(int next:graph[s]){
                indegree[next]--;
                if(indegree[next]==0){
                    start.push(next);
                }
            }
        }
        for(int in:indegree){
            if(in!=0){
                return false;
            }
        }
        return true;
    }
};