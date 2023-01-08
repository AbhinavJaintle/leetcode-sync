class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if(finalSum%2!=0) return {};
        unordered_map<long long,int> m;
        vector<long long> v;
        long long i = 2;
        while(finalSum!=0){
            if(m[finalSum-i]!=0||finalSum-i==i){
                v.push_back(finalSum);
                return v;
            }
            m[i]++;
            v.push_back(i);
            finalSum-=i;
            i+=2;
        }
        return v;
    }
};