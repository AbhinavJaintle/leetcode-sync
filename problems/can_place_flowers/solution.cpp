class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        bool fin = true;
        int sum=0;
        for(int i = 0; i<flowerbed.size()-1; i++){
            if(flowerbed[i]==1)fin=false;
            else{
                if(fin){
                    if(flowerbed[i+1]==0){
                        fin=false;
                        sum++;
                    }
                }
                else{
                    fin=true;
                }
            }
        }
        if(fin&&flowerbed[flowerbed.size()-1]==0)sum++;
        return sum>=n;
    }
};