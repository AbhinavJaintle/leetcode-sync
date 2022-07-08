class Solution {
public:
    string longestCommonPrefix(vector<string> s)
{
    int n = s.size();
    if(n==0){
        return "";
    }
    string ans = s[0];
    for(int i = 1; i<n; i++){
        int j = 0;
        while(j<ans.length() && j<s[i].length() && ans[j]==s[i][j]){
            j++;
        }
        ans = ans.substr(0,j);
    }
    return ans;
}
};