class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        unordered_map<int,int> m;
        int index=1;
        m[1]++;
        int turn = 1;
        while(1>0){
            index=(index+k*turn)%n;
            if(index==0)index=n;
            m[index]++;
            if(m[index]==2)break;
            turn++;
        }
        vector<int> v;
        for(int i = 1; i<=n; i++){
            if(!m[i])v.push_back(i);
        }
        return v;
    }
};