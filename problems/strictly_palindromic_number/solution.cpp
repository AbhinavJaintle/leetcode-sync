class Solution {
public:
    string base(int b, int n){
        string temp;
        while(n!=0){
            temp.push_back(n%b);
            n=n/b;
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
    bool isPalindrome(string s){
        int i = 0;
        int j = s.length()-1;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool isStrictlyPalindromic(int n) {
        for(int i = 2; i<=n-2; i++){
            if(!isPalindrome(base(i,n))){
                return false;
            }
        }
        return true;
    }
};