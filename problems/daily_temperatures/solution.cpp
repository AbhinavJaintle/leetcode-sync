class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> s;
        vector<int> ans(temperatures.size());
        for(int i = 0; i<temperatures.size(); i++){
            while(!s.empty()&&temperatures[i]>s.top().first){
                ans[s.top().second] = i-s.top().second;
                s.pop();
            }
            if(i==temperatures.size()-1){
                ans[i] = 0;
            }
            else{
                s.push(make_pair(temperatures[i], i));
            }
        }
        while(!s.empty()){
            ans[s.top().second] = 0;
            s.pop();
        }
        return ans;
        
    }
};