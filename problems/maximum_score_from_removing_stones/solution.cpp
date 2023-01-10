class Solution {
public:
    int maximumScore(int a, int b, int c) {
        int score=0;
        priority_queue<int> pq;
        pq.push(a);
        pq.push(b);
        pq.push(c);
        while(1<2){
            int t1= pq.top();
            pq.pop();
            int t2= pq.top();
            pq.pop();
            if(t1==0||t2==0) return score;
            score++;
            t1--;
            t2--;
            pq.push(t1);
            pq.push(t2);
        }
        return 0;
    }
};