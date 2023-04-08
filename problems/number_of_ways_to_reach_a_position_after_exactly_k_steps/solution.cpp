class Solution {
    int mod = 1000000007;
    map<pair<int,int>,int> vis;
public:
    int helper(int index, int target, int k, map<pair<int,int>,int>& m){
        if(k==0){
            if(index==target)return 1;
            return 0;
        }
        if(abs(target-index)>k)return 0;
        if(vis[{index,k}])return m[{index,k}];
        vis[{index,k}]++;
        return m[{index,k}]=(helper(index+1,target,k-1,m)%mod+helper(index-1,target,k-1,m)%mod)%mod;
    }
    int numberOfWays(int startPos, int endPos, int k) {
        map<pair<int,int>,int> m;
        vis.clear();
        return helper(startPos, endPos, k, m);
    }
};