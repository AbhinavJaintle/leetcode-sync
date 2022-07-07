class Solution {
public:
int lengthOfLongestSubstring(string s) {
    int n = s.length();
    
    vector<int>v(256,-1);
    int start = -1;
    int mx = 0;
    for(int i=0; i<n; i++){
        
    // check start is less than repeting position if not then start remain same
        if(v[s[i]]>start){
            start = v[s[i]];
        }
        v[s[i]] = i;
        mx = max(mx,i-start);
        
    }
    return mx;
}
};