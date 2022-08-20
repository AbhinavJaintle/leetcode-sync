class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans = 10e+5;
        for(int i = 0; i<blocks.length()-k+1; i++){
            int temp = 0;
            for(int j = i; j<i+k; j++){
                if(blocks[j]=='W'){
                    temp += 1;
                }
            }
            ans = min(ans,temp);
        }
        return ans;
    }
};