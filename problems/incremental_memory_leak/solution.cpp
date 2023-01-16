class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        int sum;
        int i = 1;
        while(1<2){
            if(memory1>=memory2){
                if(memory1<i){
                    sum=i;
                    break;
                }
                memory1-=i;
                i++;
            }
            else{
                if(memory2<i){
                    sum=i;
                    break;
                }
                memory2-=i;
                i++;
            }
        }
        return {sum,memory1,memory2};
    }
};