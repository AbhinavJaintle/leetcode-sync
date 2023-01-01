class Solution {
public:
    unordered_map<int,int> vis;
    unordered_map<int,bool> m;
    bool isPrime(int n){
        if(vis[n]!=0){
            return m[n];
        }
        vis[n]++;
        if(n<=1){
            return m[n]=false;
        }
        for(int i =2; i*i<=n; i++){
            if(n%i==0){
                return m[n]=false;
            }
        }
        return m[n]=true;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int> ans={-1,-1};
        int prev=0;
        int mini = INT_MAX;
        for(int i = left; i<=right; i++){
            if(isPrime(i)){
                if(prev!=0){
                    if((i-prev)<mini){
                        ans={prev,i};
                        mini=i-prev;
                        if(mini==2) return ans;
                    }
                }
                prev=i;
            }
        }
        return ans;
    }
};