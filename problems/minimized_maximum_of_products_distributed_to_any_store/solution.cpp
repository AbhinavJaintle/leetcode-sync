class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int start = 1;
        int end = *max_element(quantities.begin(),quantities.end());
        while(start<end){
            int mid = start+(end-start)/2;
            int count = 0;
            for(auto&i:quantities){
                count = i%mid==0?count+i/mid:count+i/mid+1;
                if(count>n)break;
            }
            if(count>n)start=mid+1;
            else end=mid;
        }
        return start;
    }
};