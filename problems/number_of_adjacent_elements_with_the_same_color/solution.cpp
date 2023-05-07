class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        int curr=0;
        vector<int> nums(n,0);
        vector<int> ans(queries.size());
        bool t1=false, t2=false;
        for(int i = 0; i<queries.size(); i++){
            t1=false;
            t2=false;
            if(nums[queries[i][0]]!=0){
            if(queries[i][0]!=0){
                if(nums[queries[i][0]-1]==nums[queries[i][0]])t1=true;
            }
            if(queries[i][0]!=n-1){
                if(nums[queries[i][0]+1]==nums[queries[i][0]])t2=true;
            }
            if(t1&&t2)curr-=2;
            else if(t1||t2)curr-=1;
            }
            t1=false;
            t2=false;
            nums[queries[i][0]]=queries[i][1];
            if(queries[i][0]!=0){
                if(nums[queries[i][0]-1]==nums[queries[i][0]])t1=true;
            }
            if(queries[i][0]!=n-1){
                if(nums[queries[i][0]+1]==nums[queries[i][0]])t2=true;
            }
            if(t1&&t2)curr+=2;
            else if(t1||t2)curr+=1;
            ans[i]=curr;
        }
        return ans;
    }
};