class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        unordered_map<int,int> r;
        int count=0;
        int target=grid.size()-1;
        while(target>0){
        bool flag=true;
        for(int i = 0; i<grid.size(); i++){
            if(r[i]==-1)continue;
            int n = 0;
            for(int j = grid[0].size()-1; j>=0&&grid[i][j]==0&&n<target; j--){
                n++;
            }
            if(n!=target){
                r[i]++;
                continue;
            }
            count+=i-grid.size()+1+target+r[i];
            r[i]=-1;
            flag=false;
            break;
        }
        if(flag)return -1;
        target--;
        }
        return count;
    }
};