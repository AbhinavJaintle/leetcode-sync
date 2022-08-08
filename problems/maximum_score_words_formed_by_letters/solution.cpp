class Solution {
public:
    
    int scoreword(int t, int index, int ans, map<char,int>& letterscore, vector<string>& words, vector<int>& score){
        if(t==2){
            return ans;
        }
        if(index==words.size()){
            return ans;
        }
        map<char, int> m = letterscore;
        int temp = 0;
        int flag = 0;
        for(int i = 0; i<words[index].size(); i++){
            if(m[words[index][i]]<1){
                flag = 1;
                break;
            }
            temp+=score[words[index][i]-97];
            m[words[index][i]]-=1;
        }
        int ret;
        if(flag==1){
            ret = scoreword(t, index+1, ans, letterscore, words, score);
        }
        else{
        ret = max(scoreword(t-1, index+1, ans+temp, m, words, score), scoreword(t, index+1, ans, letterscore, words, score));
        }
        
        return ret;
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        map<char, int> letterscore;
        for(int i =0; i<letters.size(); i++){
            letterscore[letters[i]] += 1;
        }
        return scoreword(0,0, 0, letterscore, words, score);
    }
};