class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string,int> m;
        stringstream ss1(s1);
        stringstream ss2(s2);
        string word;
        while(ss1>>word)m[word]++;
        while(ss2>>word)m[word]++;
        vector<string> v;
        for(auto&i:m){
            if(i.second==1)v.push_back(i.first);
        }
        return v;
    }
};