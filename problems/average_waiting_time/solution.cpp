class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        long free = 0;
        double wait = 0;
        for(auto&i:customers){
            int arv = i[0];
            if(arv<free){
                wait+=free-arv+i[1];
                free+=i[1];
            }
            else{
                free=arv+i[1];
                wait+=i[1];
            }
            
        }
        return wait/(double)customers.size();
    }
};