class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int start=1;
        int prev=1;
        for(int i = 0; i<derived.size()-1; i++){
            prev=prev^derived[i+1];
        }
        prev=prev^derived[0];
        return start==prev;
    }
};