class Solution {
public:
    vector<string> v= {};
    void helper(int index, string curr){
        if(index==curr.length()){
            v.push_back(curr);
            return;
        }
        helper(index+1,curr);
        if((curr[index]-'0'>=0)&&(curr[index]-'0'<=9))return;
        if(curr[index]<91){
            curr[index]+=32;
            helper(index+1,curr);
            curr[index]-=32;
        }
        else{
            curr[index]-=32;
            helper(index+1,curr);
            curr[index]+=32;
        }
    }
    vector<string> letterCasePermutation(string s) {
        helper(0,s);
        return v;
    }
};