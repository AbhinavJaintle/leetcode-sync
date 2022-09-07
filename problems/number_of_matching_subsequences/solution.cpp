class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int count = 0;
        map<string,int> m;
        for(auto&i:words){
            m[i]++;
        }
        for(auto&i:m){
            int len = i.first.length();
            int start = 0;
            for(int j = 0; j<s.length()&&start<len; j++){
                if(s[j]==i.first[start]){
                    start++;
                }                
            }
            if(start==len){
                count+=i.second;
            }
        }
        return count;
    }
};