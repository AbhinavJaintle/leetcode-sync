class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string temp1;
        for(auto&i:word1){
            temp1+=i;
        }
        string temp2;
        for(auto&i:word2){
            temp2+=i;
        }
        return (temp1==temp2);
    }
};