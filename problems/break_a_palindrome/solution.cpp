class Solution {
public:
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
    string breakPalindrome(string palindrome) {
        vector<string> v;
        for(int i = 0; i<palindrome.length(); i++){
            string temp = palindrome;
            if(temp[i]=='a'){
                temp[i]='b';
            }
            else{
                temp[i]='a';
            }
            if(!isPalindrome(temp)){
                v.push_back(temp);
            }
        }
        if(v.size()==0){
            return "";
        }
        sort(v.begin(),v.end());
        return v[0];
    }
};