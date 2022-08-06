class Solution {
public:
    
    bool word(string s, int index, vector<string>& wordDict, vector<int>& df){
        if(df[index]!=-1){
            return df[index];
        }
        bool champ = false;
        for(int i = 0; i<wordDict.size(); i++){
            if(s.substr(index, wordDict[i].size())==wordDict[i]){
                champ = word(s, index+wordDict[i].size(), wordDict, df);
            }
            if(champ){
                return df[index] = champ;
            }
        }
        return df[index] = false;
    }
        
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> df(s.length()+1,-1);
        df[s.length()] = 1;
        return word(s, 0, wordDict, df);
    }
};