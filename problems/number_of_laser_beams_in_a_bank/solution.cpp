class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int prev=0, sum=0;
        for(int i = 0; i<bank.size(); i++){
            int temp=0;
            for(int j = 0; j<bank[0].length(); j++){
                if(bank[i][j]=='1') temp++;
            }
            sum+=temp*prev;
            prev=temp!=0?temp:prev;
        }
        return sum;
    }
};