class Solution {
public:
    bool palindrome(string s){
    int n = s.length();
    int i = 0;
    int j = n-1;
    while(i<j){
        if(s[i]!=s[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}
int countSubstrings(string s)
{
    int n = s.length();
    int count = 0;
    for(int i = 0; i<n; i++){
        for(int j = i+1; j<=n; j++){
            string sub = s.substr(i,j-i);
            if(palindrome(sub)){
                count++;
            }
        }
    }
    return count;
}
};