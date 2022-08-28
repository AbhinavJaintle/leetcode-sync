class Solution {
public:
    int calculate(vector<int> v, vector<int> pretravel){
        int curr = 0;
        int ans = 0;
        for(auto&i:v){
            ans+=pretravel[i]-pretravel[curr]+1;
            curr=i;
        }
        return ans;
    }
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        vector<int> pretravel(travel.size()+1,0);
        for(int i = 1; i<travel.size()+1; i++){
            pretravel[i]=travel[i-1]+pretravel[i-1];
        }
        vector<int> paper;
        vector<int> metal;
        vector<int> glass;
        for(int i = 0; i<garbage.size(); i++){
            for(int j =0; j<garbage[i].size(); j++){
                if(garbage[i][j]=='M'){
                    metal.push_back(i);
                }
                else if(garbage[i][j]=='G'){
                    glass.push_back(i);
                }
                else{
                    paper.push_back(i);
                }
            }
        }
        return calculate(paper,pretravel)+calculate(glass,pretravel)+calculate(metal,pretravel);
    }
};