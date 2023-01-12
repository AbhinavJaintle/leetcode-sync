class Solution {
public:
    int longestSubstring(string s, int k) {
        if(s.length()<k) return 0;
        if(k==1) return s.length();
        int sum=0;
        for(int i = 0; i<s.length(); i++){
            unordered_map<char,int> m;
            m[s[i]]++;
            int un = 1;
            for(int j = i+1; j<s.length(); j++){
                m[s[j]]++;
                if(m[s[j]]==1) un++;
                if(m[s[j]]==k)un--;
                if(un==0) sum=max(sum,j-i+1);
            }
        }
        return sum;
    }
};