class Solution {
public:
    int power(long long x, unsigned int y, int p){
        int res = 1;
 
        x = x % p; 
  
        if (x == 0) return 0; 
 
        while (y > 0){
            if (y & 1)res = (res*x) % p;
 
            y = y>>1; // y = y/2
            x = (x*x) % p;
        }
        return res;
    }
    int countWays(vector<vector<int>>& ranges) {
        long long mod = 1e9+7;
        sort(ranges.begin(),ranges.end());
        unsigned int groups = 1;
        for(int i = 1; i<ranges.size(); i++){
            if(ranges[i][0]>ranges[i-1][1]){
                groups++;
            }
            ranges[i][1]=max(ranges[i][1],ranges[i-1][1]);
        }
        return power(2,groups,mod);
    }
};