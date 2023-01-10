class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        unordered_map<long long,long long> m;
        long long  day=0;
        for(int i = 0; i<tasks.size(); i++){
            day++;
            if(m[tasks[i]]>day){ 
                day+=m[tasks[i]]-day;
            }
            m[tasks[i]]=day+space+1;
            
        }
        return day;
    }
};