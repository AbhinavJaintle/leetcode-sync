class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& grid) {
        vector<vector<int>> l=grid;
        vector<vector<int>> r=grid;
        for(int i = 0; i<grid[0].size(); i++){
            unordered_map<int,int> m;
            int count=0;
            int index=0;
            int y = i;
            while(index<grid.size()&&y<grid[0].size()){
                if(m[grid[index][y]]==0){
                    count++;
                    m[grid[index][y]]++;
                }
                l[index][y]=count;
                index++;
                y++;
            }
        }
        for(int i = 1; i<grid.size(); i++){
            unordered_map<int,int> m;
            int count=0;
            int index=0;
            int y = i;
            while(y<grid.size()&&index<grid[0].size()){
                if(m[grid[y][index]]==0){
                    count++;
                    m[grid[y][index]]++;
                }
                l[y][index]=count;
                index++;
                y++;
            }
        }
        for(int i = grid[0].size()-1; i>=0; i--){
            unordered_map<int,int> m;
            int count=0;
            int index=grid.size()-1;
            int y = i;
            while(index>=0&&y>=0){
                if(m[grid[index][y]]==0){
                    count++;
                    m[grid[index][y]]++;
                }
                r[index][y]=count;
                index--;
                y--;
            }
        }
        for(int i = grid.size()-2; i>=0; i--){
            unordered_map<int,int> m;
            int count=0;
            int index=grid[0].size()-1;
            int y = i;
            while(y>=0&&index>=0){
                if(m[grid[y][index]]==0){
                    count++;
                    m[grid[y][index]]++;
                }
                r[y][index]=count;
                index--;
                y--;
            }
        }
        for(int i = 0; i<grid.size(); i++){
            for(int j = 0; j<grid[0].size(); j++){
                int ops1=0;
                int ops2=0;
                if(i-1>=0&&j-1>=0){
                    ops1 = l[i-1][j-1];
                }
                if(i+1<grid.size()&&j+1<grid[0].size()){
                    ops2=r[i+1][j+1];
                }
                grid[i][j]=abs(ops1-ops2);
            }
        }
        return grid;
    }
};