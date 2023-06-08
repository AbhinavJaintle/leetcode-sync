class Solution {
public:
    int reinitializePermutation(int n) {
        vector<int> perm(n);
        vector<int> arr(n);
        for(int i = 0; i<n; i++)perm[i]=i;
        arr=perm;
        int count = 0;
        while(arr!=perm||(count==0)){
            vector<int> temp=arr;
            for(int i = 0; i<n; i++){
                if(i%2==0){
                    arr[i]=temp[i/2];
                }
                else{
                    arr[i]=temp[n/2+(i-1)/2];
                }
            }
            count++;
        }
        return count;
    }
};