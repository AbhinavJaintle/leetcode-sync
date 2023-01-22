class Solution {
    vector<vector<string>> ans;
    bool isPalindrome(string c){
        if(c.length()==0)return false;
        int i = 0, j = c.length()-1;
        while(i<j){
            if(c[i]!=c[j])return false;
            i++;
            j--;
        }
        return true;
    }
public:
    void helper(int index, vector<string>& curr, string s, string c){
        if(index==s.length()){
            if(isPalindrome(c)){
                curr.push_back(c);
                ans.push_back(curr);
                curr.pop_back();
                return;
            }
            return;
        }
        c.push_back(s[index]);
        if(isPalindrome(c)){
            curr.push_back(c);
            helper(index+1,curr,s,"");
            curr.pop_back();
        }
        helper(index+1,curr,s,c);
    }
    vector<vector<string>> partition(string s) {
        vector<string>curr;
        helper(0,curr,s,"");
        return ans;
    }
};