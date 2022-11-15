class Solution {
public:
    bool isPalindrome(int x) {
        string temp = to_string(x);
        int start = 0;
        int end = temp.length()-1;
        while(start<end){
            if(temp[start]!=temp[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
};