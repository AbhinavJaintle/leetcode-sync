class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& segments) {
        int maxi=0;
        for(auto&i:segments){
            maxi=max(maxi,i[1]);
        }
        vector<long long> v(maxi+1,0);
        unordered_map<int,int> m;
        unordered_map<int,long long> pref;
        for(auto&i:segments){
            v[i[0]]+=i[2];
            v[i[1]]-=i[2];
            m[i[1]]=1;
        }
        long long prev=0;
        for(int j = 0; j<maxi+1; j++){
                v[j]+=prev;
                prev=v[j];
        }
        vector<vector<long long>> ans;
        for(int i = 0; i<maxi+1; i++){
            if(v[i]==0)continue;
            int index=i;
            long long curr=v[i];
            while(i<maxi+1&&m[i]==0&&v[i]==curr){
                i++;
            }
            ans.push_back({index,i,v[i-1]});
            if(m[i]==1)m[i]--;
            i--;
        }
        return ans;
    }
};