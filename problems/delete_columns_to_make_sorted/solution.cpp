class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int count=0;
        for(int i = 0; i<strs[0].length(); i++){
            string temp;
            for(auto&j:strs){
                temp.push_back(j[i]);
            }
            string t = temp;
            sort(temp.begin(),temp.end());
            if(temp!=t) count++;
        }
        return count;
    }
};