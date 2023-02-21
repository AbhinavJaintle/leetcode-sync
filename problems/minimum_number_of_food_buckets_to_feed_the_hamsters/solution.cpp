class Solution {
public:
    int minimumBuckets(string hamsters) {
        int start1=0;
        unordered_map<int,int> m;
        for(int i = 0; i<hamsters.length(); i++){
            if(m[i])continue;
            if(hamsters[i]=='H'){
                if(i+1<hamsters.length()&&hamsters[i+1]=='.'){
                    start1++;
                    m[i+2]++;
                }
                else if(i-1>=0&&hamsters[i-1]=='.'){
                    start1++;
                }
                else{
                    return -1;
                }
            }
        }
        
        return start1;
    }
};