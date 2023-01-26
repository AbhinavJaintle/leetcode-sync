class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int maxi=0;
        int prev=0;
        for(auto&i:gain){
            prev+=i;
            maxi=max(maxi,prev);
        }
        return maxi;
    }
};