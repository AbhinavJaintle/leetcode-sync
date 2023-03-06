class Solution {
public:
    int helper(int index, string s, string curr, unordered_map<string,int>&m){
        if(index==s.length()){
            if(curr!=""&&m[curr])return INT_MIN+10;
            return curr==""?0:1;
        }
        int ans=0;
        if(curr!=""&&!m[curr]){
            m[curr]++;
            ans = 1+helper(index,s,"",m);
            m[curr]--;
        }
        curr.push_back(s[index]);
        ans=max(ans,helper(index+1,s,curr,m));;
        return ans;
    }
    int maxUniqueSplit(string s) {
        unordered_map<string,int> m;
        return helper(0,s,"",m);
    }
};