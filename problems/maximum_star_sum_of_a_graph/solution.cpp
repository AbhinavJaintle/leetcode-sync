class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        unordered_map<int,int> m;
        map<int,priority_queue<int>> p;
        for(int i = 0; i<vals.size(); i++){
            m[i]= vals[i];
        }
        for(auto&i:edges){
            p[i[0]].push(m[i[1]]);
            p[i[1]].push(m[i[0]]);
        }
        int sum = -1*1e6;
        for(int i = 0; i<vals.size(); i++){
            int temp = m[i];
            int flag= 0;
            int index = k;
            while(index!=0&&!p[i].empty()){
                if(p[i].top()<0){
                    break;
                }
                temp+=p[i].top();
                p[i].pop();
                index--;
            }

            sum=max(sum,temp);
        }
        return sum;
    }
};