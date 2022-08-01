class Solution {
public:
    int corner;
    int bottom;
    vector<vector<int>> v;
    
    int path(int a, int b){
        
        if(a>bottom-1||b>corner-1){
            return 0;
        }
        if(v[a][b]!=0){
            return v[a][b];
        }
        if(a==bottom-1&&b==corner-1){
            return 1;
        }
        int temp = path(a+1, b)+path(a,b+1);
        return v[a][b] = temp;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m , vector<int>(n , 0));
        v = dp;
        corner = n;
        bottom = m;
        return path(0,0);
    }
};