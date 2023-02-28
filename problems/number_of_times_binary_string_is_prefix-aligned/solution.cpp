class Solution {
public:
    int numTimesAllBlue(vector<int>& flips) {
        int highest=0;
        int curr=0;
        int sum=0;
        for(auto&i:flips){
            highest=max(highest,i);
            curr++;
            if(highest==curr)sum++;
        }
        return sum;
    }
};