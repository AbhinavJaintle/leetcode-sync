class Solution {
public:
    int power(int n){
        if(n==1) return 0;
        int sum;
        if(n%2==0){
            sum=1+power(n/2);
        }
        else{
            sum=1+power(3*n+1);
        }
        return sum;
    }
    int getKth(int lo, int hi, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i = lo; i<=hi; i++){
            pq.push({power(i),i});
        }
        while(k-1){
            pq.pop();
            k--;
        }
        
        return pq.top().second;
    }
};