class Solution {
public:
    unordered_map<int,int> l;
    unordered_map<int,int> r;

int modMul(int a, int b,int mod)
{
    int res = 0; 
 
    a %= mod;
 
    while (b) {
        if (b & 1)
            res = (res + a) % mod;
 
        a = (2 * a) % mod;
 
        b >>= 1; 
    }
 
    return res;
}
 

    int power(int x, int y, int p)
{
    int res = 1;
 
    x = x % p; 
 
    while (y > 0)
    {
     
        if (y & 1)
            res = modMul(res,x,p);
 
        y = y >> 1; 
        x = modMul(x, x, p);
    }
    return res;
}
 
int modInverse(int n, int p)
{
    return power(n, p - 2, p);
}
 

int nCr(int n, int r, int p)
{
    if (n < r)
        return 0;
    if (r == 0)
        return 1;
 

    int fac[n + 1];
    fac[0] = 1;
    for (int i = 1; i <= n; i++)
        fac[i] = modMul(fac[i - 1],i,p);
 
    return modMul(modMul(fac[n],modInverse(fac[r], p),p),modInverse(fac[n - r], p),p);
}

    void createBST(vector<vector<int>>& v, int root, int num){
        if(num<root){
            l[root]++;
            if(v[root][0]==0){
                v[root][0]=num;
            }
            else createBST(v,v[root][0],num);
        }
        else{
            r[root]++;
            if(v[root][1]==0){
                v[root][1]=num;
            }
            else createBST(v,v[root][1],num);
        }
    }
    int numOfWays(vector<int>& nums) {
        // l.clear();
        // r.clear();
        vector<vector<int>> v(nums.size()+1, vector<int>(2,0));
        for(int i = 1; i<nums.size(); i++){
            createBST(v,nums[0],nums[i]);
        }
        int count = 1;
        int mod = 1e9+7;
        for(int i = 1; i<nums.size()+1; i++){
            if((l[i]!=0)&&(r[i]!=0))count = modMul(count,(nCr(l[i]+r[i]-1,l[i],1e9+7)+nCr(l[i]+r[i]-1,r[i],1e9+7))%(mod),mod);
        }
        return count-1;
    }
};