class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> m;
        for(auto&i:arr){
            m[i]++;
        }
        arr={};
        int count=0;
        for(auto&i:m){
            arr.push_back(i.second);
            count++;
        }
        sort(arr.begin(),arr.end());
        for(auto&i:arr){
            if(i>k)break;
            k-=i;
            count--;
        }
        return count;
    }
};