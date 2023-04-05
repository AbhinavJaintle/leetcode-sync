class Solution {
public:
    int minNumberOfFrogs(string s) {
        int c = 0;
        int r = 0;
        int o = 0;
        int a = 0;
        int k = 0;
        int curr=0;
        int maxi=0;
        for(auto&i:s){
            if(i=='c')c++;
            if(i=='r')r++;
            if(i=='o')o++;
            if(i=='a')a++;
            if(i=='k')k++;
            if(c<r||r<o||o<a||a<k)return -1;
            if(i=='c'){
                curr++;
                maxi=max(maxi,curr);
            }
            if(i=='k'){
                curr--;
            }
        }
        if(c!=r||r!=o||o!=a||a!=k)return -1;
        return maxi;
    }
};