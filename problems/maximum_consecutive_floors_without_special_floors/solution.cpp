class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        sort(special.begin(),special.end());
        special.push_back(top+1);
        int curr = special[0]-bottom;
        for(int i = 0; i<special.size()-1; i++){
            curr = max(curr,special[i+1]-special[i]-1);
        }
        return curr;
    }
};