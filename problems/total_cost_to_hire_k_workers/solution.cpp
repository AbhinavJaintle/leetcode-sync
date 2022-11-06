class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long cost = 0;
        
        priority_queue<int, vector<int>, std::greater<int> > pq1;
        priority_queue<int, vector<int>, std::greater<int> > pq2;
        
        int beginright = 0+candidates;
        int endleft = costs.size()-candidates;
        for(int i = 0; i<beginright; i++){
            pq1.push(costs[i]);
            costs[i]=1e+6;
        }
        for(int i = endleft; i<costs.size(); i++){
            pq2.push(costs[i]);
            
            costs[i]=1e+6;
        }
        for(int i = 0; i<k; i++){
            if(pq2.empty()||!pq1.empty()&&pq1.top()<=pq2.top()){
                cost+=pq1.top();
                pq1.pop();
                
                if(beginright<costs.size()){
                    pq1.push(costs[beginright]);
                    costs[beginright]=1e+6;
                }
                beginright++;
            }
            else{
                cost+=pq2.top();
                pq2.pop();
                endleft--;
                if(endleft>=0){
                    pq2.push(costs[endleft]);
                    costs[endleft]=1e+6;
                }
            }
            
        }
        return cost;
    }
};