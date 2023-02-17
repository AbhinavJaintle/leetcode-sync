class Solution {
public:
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>> v(n,vector<int>(n,1));
        for(auto&i:mines){
            v[i[0]][i[1]]=0;
        }
        vector<vector<int>> v2 = v;
        for(int i = 0; i<n; i++){
            int curr=0;
            for(auto&j:v[i]){
                if(j==1)curr++;
                else{
                    curr=0;
                }
                j=curr;
            }
            curr=0;
            for(int j = n-1; j>=0; j--){
                if(v2[i][j]==1){
                    curr++;
                }
                else{
                    curr=0;
                }
                v[i][j]=min(v[i][j],curr);
            }
        }
        int maxi=0;
        for(int i = 0; i<n; i++){
            int curr=0;
            for(int j = 0;j<n; j++){
                if(v2[j][i]==1)curr++;
                else{
                    curr=0;
                }
                v[j][i]=min(v[j][i],curr);
            }
            curr=0;
            for(int j = n-1; j>=0; j--){
                if(v2[j][i]==1){
                    curr++;
                }
                else{
                    curr=0;
                }
                v[j][i]=min(v[j][i],curr);
                maxi=max(maxi,v[j][i]);
            }
        }
        return maxi;
    }
};