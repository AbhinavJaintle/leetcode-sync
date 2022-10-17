class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_map<char,int> m;
        int count = 0;
        for(auto&i: sentence){
            m[i]+=1;
            if(m[i]==1){
                count++;
            }
        }
        return (count==26);
    }
};