class Solution {
public:
    bool isThree(int n) {
        int count = 1;
        int index = 2;
        while(index<n&&count<4){
            if(n%index==0){
                count++;
            }
            index++;
        }
        return count==2;
    }
};