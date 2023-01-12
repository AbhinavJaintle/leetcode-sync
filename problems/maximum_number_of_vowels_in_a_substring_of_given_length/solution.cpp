class Solution {
public:
    bool isVowel(char c){
        return (c=='a'||c=='e'||c=='i'||c=='o'||c=='u');
    }
    int maxVowels(string s, int k) {
        int windowSize=0;
        int vow = 0;
        int prev=0;
        int sum=0;
        for(int i = 0; i<s.length(); i++){
            windowSize++;
            if(isVowel(s[i])) vow++;
            if(windowSize>k){
                if(isVowel(s[prev])){
                    vow--;
                }
                prev++;
            }
            sum=max(sum,vow);
        }
        return sum;
    }
};