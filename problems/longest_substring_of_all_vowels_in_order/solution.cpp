class Solution {
public:
    int longestBeautifulSubstring(string word) {
        int l = 0, r= 0;
        int n = word.size();
        int res = 0;
        while(l<n){
            if(word[l] == 'a'){
                r = l + 1;
                while(r<n && word[r]=='a')++r;
                if(word[r]!='e') {l=r;continue;}
                while(r<n && word[r]=='e')++r;
                if(word[r]!='i') {l=r;continue;}
                while(r<n && word[r]=='i')++r;
                if(word[r]!='o') {l=r;continue;}
                while(r<n && word[r]=='o')++r;
                if(word[r]!='u') {l=r;continue;}
                while(r<n && word[r]=='u'){res = max(res,r-l+1);++r;}
                l = r;
            }
            else{
                ++l;
            }
        }
        return res;
    }
};