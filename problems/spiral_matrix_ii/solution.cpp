class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int u,l, b, e;
        u=0;
        l=n-1;
        b=0;
        e=n-1;
        int count=0;
        bool flag=true;
        vector<vector<int>> v(n,vector<int>(n));
        while(count!=n*n){
            if(flag){
                for(int i = b; i<=e; i++){
                    count++;
                    v[u][i]=count;
                }
                u++;
                for(int i = u; i<=l; i++){
                    count++;
                    v[i][e]=count;
                }
                e--;
                flag=false;
            }
            else{
                for(int i = e; i>=b; i--){
                    count++;
                    v[l][i]=count;
                }
                l--;
                for(int i = l; i>=u; i--){
                    count++;
                    v[i][b]=count;
                }
                b++;
                flag=true;
            }
        }
        return v;
    }
};