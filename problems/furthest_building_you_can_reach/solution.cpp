class Solution {
public:
    bool check(vector<int> &v, int br, int ld, int m){
        int n = v.size();
        vector<int> ans;
        for(int i=1;i<m;i++){
            if(v[i]-v[i-1]>0)
                ans.push_back(v[i]-v[i-1]);
        }
        if(ld>=ans.size())
            return true;
        sort(ans.begin(),ans.end());
        for(int i=ans.size()-ld-1;i>=0;i--){
            if(br>=ans[i])
                br-=ans[i];
            else
                return false;
        }
        return true;
    }
    int furthestBuilding(vector<int>& v, int br, int ld) {
        int n = v.size();
        int l=0,r=n;
        int ans = 0;
        while(l<=r){
            int m = (l+r)/2;
            if(check(v,br,ld,m)){
                ans=m;
                l=m+1;
            }
            else
                r=m-1;
        }
        return ans-1;
    }
};