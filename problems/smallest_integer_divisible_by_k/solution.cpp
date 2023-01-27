class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k==1)return 1;
        if(k%2==0)return -1;
        unordered_map<int,int> m;
        int prev=11;
        int index=2;
        while(!m[prev]){
            m[prev]++;
            if(prev%k==0)return index;
            index++;
            int rem=prev%k;
            prev=rem*10+1;
        }
        return -1;
    }
};