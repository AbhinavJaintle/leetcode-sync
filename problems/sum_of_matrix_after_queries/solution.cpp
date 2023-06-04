class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        unordered_map<int,int> row;
        unordered_map<int,int> col;
        unordered_map<int,int> rc;
        unordered_map<int,int> cc;
        priority_queue<pair<int,int>> r;
        priority_queue<pair<int,int>> c;
        int count=0;
        long long ans=0;
        for(auto&i:queries){
            count++;
            if(i[0]==0){
                row[i[1]]=i[2];
                rc[i[1]]=count;
            }
            else{
                col[i[1]]=i[2];
                cc[i[1]]=count;
            }
        }
        for(auto&i:rc){
            r.push({i.second,row[i.first]});
        }
        for(auto&i:cc){
            c.push({i.second,col[i.first]});
        }
        int rcount=0;
        int ccount=0;
        int aa = 0;
        while(aa!=n*n&&(!r.empty()||!c.empty())){
            if(r.empty()){
                ans+=(n-rcount)*c.top().second;
                c.pop();
                ccount++;
                aa+=n-rcount;
            }
            else if(c.empty()){
                ans+=(n-ccount)*r.top().second;
                r.pop();
                rcount++;
                aa+=n-ccount;
            }
            else if(r.top().first>c.top().first){
                ans+=(n-ccount)*r.top().second;
                r.pop();
                rcount++;
                aa+=n-ccount;
            }
            else{
                ans+=(n-rcount)*c.top().second;
                c.pop();
                ccount++;
                aa+=n-rcount;
            }
        }
        return ans;
    }
};