class Solution {
    unordered_map<int,int> dp;
public:
    int fact(int n)
    {
        if (n == 0 || n == 1)
            return 1;
        if(dp[n]!=0)return dp[n];
        return dp[n] = n * fact(n - 1);
    }
    string getPermutation(int n, int k) {
        string ans;
        unordered_map<int,int> m;
        int count = 1;
        int index=1;
        int num=n-1;
        while(num!=-1){
            int temp = fact(num);
            if(k<=temp){
                for(int i = 1; i<=n; i++){
                    if(m[i]==0){
                        count--;
                    }
                    if(count==0){
                        m[i]++;
                        ans+=to_string(i);
                        count=1;
                        num--;
                        break;
                    }
                }
            }
            else{
                count++;
                k-=temp;
            }
        }   
        return ans;
    }
};