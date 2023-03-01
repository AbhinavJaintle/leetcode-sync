class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        vector<int> v1;
        vector<int> v2;
        int n = 1;
        while(n<bound){
            v1.push_back(n);
            if(x==1)break;
            n*=x;
        }
        n = 1;
        while(n<bound){
            v2.push_back(n);
            if(y==1)break;
            n*=y;
        }
        vector<int> ans;
        int index=0;
        unordered_map<int,int> m;
        for(auto&i:v1){
            for(auto&j:v2){
                if(i+j>bound)break;
                if(m[i+j])continue;
                m[i+j]++;
                ans.push_back(i+j);
            }
        }
        return ans;
    }
};