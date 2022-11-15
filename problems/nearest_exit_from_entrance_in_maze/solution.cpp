class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        vector<pair<int,int>> n = {{1,0},{-1,0},{0,-1},{0,1}};
        queue<pair<pair<int,int>,int>> q;
        q.push({{entrance[0],entrance[1]},0});
        map<pair<int,int>,int> m;
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            if(m[{temp.first.first,temp.first.second}]==1){
                continue;
            }
            m[{temp.first.first,temp.first.second}]=1;
            for(auto&i:n){
                if(temp.first.first+i.first<0||temp.first.first+i.first>=maze.size()||temp.first.second+i.second<0||temp.first.second+i.second>=maze[0].size()){
                    if(temp.first.first!=entrance[0]||temp.first.second!=entrance[1]){
                        return temp.second;
                    }
                }
                else if(maze[temp.first.first+i.first][temp.first.second+i.second]=='.'){
                    q.push({{temp.first.first+i.first,temp.first.second+i.second},temp.second+1});
                }
            }
        }
        return -1;
    }
};