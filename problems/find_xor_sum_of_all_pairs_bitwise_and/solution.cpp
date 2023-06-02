class Solution {
public:
    int getXORSum(vector<int>& arr1, vector<int>& arr2) {
        vector<int> count(32);
        for(auto&i:arr2){
            int n = 0;
            while(i){
                if(i&1)count[n]++;
                n++;
                i=i>>1;
            }
        }
        vector<int> ans(32);
        for(auto&i:arr1){
            int n = 0;
            int temp=0;
            while(i){
                if(i&1){
                    if(count[n]%2){
                        ans[n]++;
                    }
                }
                n++;
                i=i>>1;
            }
        }
        int temp=0;
        for(int i = 31; i>=0; i--){
            if(ans[i]%2){
                cout<<i;
                temp|=1;
            }
            if(i!=0)temp=temp<<1;
        }
        return temp;
    }
};