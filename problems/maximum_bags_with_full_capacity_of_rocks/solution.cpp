class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> v;
        for(int i = 0; i<capacity.size(); i++){
            v.push_back(capacity[i]-rocks[i]);
        }
        sort(v.begin(),v.end());
        int count = 0;
        int i = 0 ;
        while(additionalRocks>=0&&i<v.size()){
            additionalRocks-=v[i];
            i++;
            if(additionalRocks>=0){
                count++;
            }
        }
        return count;
    }
};