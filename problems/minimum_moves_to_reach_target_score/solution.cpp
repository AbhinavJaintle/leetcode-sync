class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int curr = 0;
        while(target!=1&&maxDoubles){
            if(target%2!=0){
                target--;
                curr++;
            }
            target/=2;
            curr++;
            maxDoubles--;
        }
        curr+=target-1;
        return curr;
    }
};