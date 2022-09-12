class Solution {
public:
    int pick(vector<int>& tokens, int power, int score, int i, int j){
        if(i>=j||score<0){
            return score;
        }
        while(i<j&&tokens[i+1]<=power){
            score++;
            power-=tokens[i+1];
            i++;
        }
        int ans = max(score,pick(tokens,power+tokens[j],score-1,i,j-1));
        return ans;
    }
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(),tokens.end());
        return pick(tokens,power,0,-1,tokens.size()-1);
    }
};