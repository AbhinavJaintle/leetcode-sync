class Solution {
public:
    int countPrefixes(vector<string>& words, string s, int sum=0) {
        for(auto&i:words){
            if(i==s.substr(0,i.length())){
                sum++;
            }
        }
        return sum;
    }
};