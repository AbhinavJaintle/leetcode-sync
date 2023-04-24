class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto&i:stones){
            pq.push(i);
        }
        int p1, p2;
        while(pq.size()>1){
            p1=pq.top();
            pq.pop();
            p2=pq.top();
            pq.pop();
            if(p1==p2){continue;}
            else pq.push(p1-p2);
        }
        return pq.empty()?0:pq.top();
    }
};