class Solution {
public:
        int maximumSum(vector<int>& arr) {
        int n=arr.size();
        vector<int> fw(n,0);
        vector<int> bw(n,0);
        int cur_max=arr[0],max_so_far=arr[0];
        fw[0]=arr[0];
        for(int i=1;i<n;i++){
            cur_max=max(arr[i],cur_max+arr[i]);
            max_so_far=max(max_so_far,cur_max);
            fw[i]=cur_max;
        }
        cur_max=max_so_far=bw[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            cur_max=max(arr[i],cur_max+arr[i]);
            max_so_far=max(max_so_far,cur_max);
            bw[i]=cur_max;
        }
        int res=max_so_far;
        for(int i=1;i<n-1;i++)
            res=max(res,fw[i-1]+bw[i+1]);
        return res;
    }
};