class Solution {
public:
    bool isPossibleToCutPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        // Here we maintain a visited array to check if we have 
        // traversed this node before
        vector <vector <int>> vis(n+1,vector <int>(m+1,0));
        queue <pair<int,int>> q;
        q.push({0,0});
        vis[0][0]=1;
        int flag = 0;
        // The flag maintains if the size of the queue was less than 2
        while(!q.empty())
        {
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            // to traverse downwards if possible
            if(row<n-1 && grid[row+1][col]==1 && vis[row+1][col]==0)
            {
                q.push({row+1,col});
                // If we have reached the destination then it 
                // implies that there were always more than 1 path
                // that existed.
                if(row+1==n-1 && col==m-1)
                    break;
                vis[row+1][col]=1;
            }
            // to traverse rightwards if possible
            if(col<m-1 && grid[row][col+1]==1 && vis[row][col+1]==0)
            {
                q.push({row,col+1});
                // If we have reached the destination then it 
                // implies that there were always more than 1 path
                // that existed.
                if(row==n-1 && col+1==m-1)
                    break;
                vis[row][col+1]=1;
            }
            if(q.size()<=1)
            {
                flag=1;
                break;
            }
        }
        return flag;
    }
};