class Solution {
public:
    int totalMoney(int n) {
        int weeks = n/7;
        int spare = n%7;
        int count= 0;
        int curr = 28;
        while(weeks){
            count+=curr;
            curr+=7;
            weeks--;
        }
        curr=n/7+1;
        while(spare){
            count+=curr;
            curr+=1;
            spare--;
        }
        return count;
    }
};