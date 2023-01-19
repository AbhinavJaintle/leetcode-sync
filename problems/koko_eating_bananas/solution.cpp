class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lim = *max_element(piles.begin(),piles.end());
        int start=1;
        int end=lim;
        int ans;
        while(start<=end){
            int mid = (start+end)/2;
            
            int temp=0;
            for(auto&j:piles){
                temp=(j%mid==0)?temp+j/mid:temp+j/mid+1;
                if(temp>h)break;
            }
            if(temp<=h){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return ans;
    }
};