class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1)return s;
        vector<vector<char>> v(numRows);
        int index=0;
        int level = 0;
        while(index<s.length()){
            v[level].push_back(s[index]);
            index++;
            level++;
            if(level==numRows){
                level-=2;
                while(index<s.length()&&level!=-1){
                    v[level].push_back(s[index]);
                    index++;
                    level--;
                }
                level+=2;
            }
        }
        string ans;
        for(auto&i:v){
            for(auto&j:i){
                ans.push_back(j);
            }
        }
        return ans;
    }
};