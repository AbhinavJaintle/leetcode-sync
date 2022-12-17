class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long count = 0;
        long long temp = cost1;
        cost1=0;
        while(cost1<=total){
            count+=(total-cost1)/cost2+1;
            cost1+=temp;
        }
        return count;
    }
};