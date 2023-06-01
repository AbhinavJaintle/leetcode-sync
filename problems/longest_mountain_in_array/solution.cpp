class Solution {
public:
    int longestMountain(vector<int>& arr) {
        bool flag = false;
        int prev = arr[0];
        int curr = 0;
        int maxi = 0;       
        for(auto&i:arr){
            if(i==prev){
                if(flag)maxi=max(maxi,curr);
                curr=1;
                flag=false;
                prev=i;
                continue;
            }
            if(flag&&i>prev){
                maxi=max(maxi,curr);
                curr=2;
                flag=false;
                prev=i;
                continue;
            }
            if(!flag&&i<prev){
                if(curr==1){
                    curr=1;
                    prev=i;
                    continue;
                }
                flag=true;
                curr++;
                prev=i;
                continue;
            }
            curr++;
            prev=i;
        }
        if(flag)maxi=max(maxi,curr);
        return maxi;
    }
};