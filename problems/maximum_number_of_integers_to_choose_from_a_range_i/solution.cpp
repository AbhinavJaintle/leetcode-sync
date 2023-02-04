class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_map<int,int> m;
        for(auto&i:banned){
            m[i]++;
        }
        int sum=0;
        long long t = 0;
        for(int i = 1; i<=n; i++){
            if(m[i]==0){
                t+=i;
                if(t<=maxSum)sum++;
                else return sum;
            }
        }
        return sum;
    }
};