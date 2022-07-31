class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> v;
        map<int, int> m;
        map<int,vector<int>> rev;
        priority_queue<int> q;
        for(int i = 0; i<nums.size(); i++){
            m[nums[i]]+=1;
        }
        for(auto it = m.begin(); it!=m.end(); it++){
            if(rev[it->second].size()==0){
                q.push(it->second);
            }
            rev[it->second].push_back(it->first);
            
        }
        while(k>0){
            for(int i = 0; i<rev[q.top()].size(); i++){
                v.push_back(rev[q.top()][i]);
                k--;
            }
            q.pop();
            
        }
        return v;
    }
};