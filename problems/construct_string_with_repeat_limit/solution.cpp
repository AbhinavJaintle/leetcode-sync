class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        unordered_map<char,int>m;
        priority_queue<char> pq;
        for(auto&i:s){
            if(m[i]==0) pq.push(i);
            m[i]++;
        }
        char curr = pq.top();
        int streak=0;
        string ans;
        while(!pq.empty()){
            ans.push_back(curr);
            m[curr]--;
            streak++;
            if(m[curr]==0){
                pq.pop();
                streak=0;
                if(pq.empty()) break;
                curr=pq.top();
            }
            else{
                if(streak==repeatLimit){
                    streak=0;
                    pq.pop();
                    if(pq.empty()) break;
                    ans.push_back(pq.top());
                    m[pq.top()]--;
                    if(m[pq.top()]==0) pq.pop();
                    pq.push(curr);
                }
            }
        }
        return ans;
    }
};