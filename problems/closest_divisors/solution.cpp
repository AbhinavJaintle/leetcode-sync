class Solution {
public:
    pair<int,int> helper(long long n){
        long long mini = 1e10;
        pair<int,int> p = {1,n};
        for(int i = 2; i<=sqrt(n); i++){
            if(n%i==0){
                if(abs(i-n/i)<mini){
                    p={i,n/i};
                    mini=abs(i-n/i);
                }
            }
        }
        return p;
    }
    vector<int> closestDivisors(int num) {
        pair<int,int> p1 = helper(num+1);
        pair<int,int> p2 = helper(num+2);
        if(abs(p1.first-p1.second)>abs(p2.first-p2.second)){
            return {p2.first,p2.second};
        }
        return {p1.first,p1.second};
    }
};