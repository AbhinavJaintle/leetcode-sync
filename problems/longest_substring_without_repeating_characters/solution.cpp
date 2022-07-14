class Solution {
public:
    int lengthOfLongestSubstring(string s)
{
    int start = -1;
    int mx = 0;
    vector<int> v(256,-1);
    for(int i =0; i<s.length();i++){
        if(v[s[i]]>start){
            start = v[s[i]];
        }
        v[s[i]] = i;
        mx = max(mx, i-start);
    }
    return mx;
}
};