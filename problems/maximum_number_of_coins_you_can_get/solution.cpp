class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int sum=0;
        sort(piles.begin(),piles.end());
        int b = 0;
        int l = piles.size()-1;
        while(b<l){
            b++;
            l-=2;
            sum+=piles[l+1];
        }
        return sum;
    }
};