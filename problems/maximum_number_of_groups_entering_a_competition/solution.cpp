class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        int prev=1;
        int curr=0;
        while(curr+prev<=grades.size()){
            curr+=prev;
            prev++;
        }
        return prev-1;
    }
};