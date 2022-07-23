class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        if(suits[0]==suits[1]&&suits[0]==suits[2]&&suits[0]==suits[3]&&suits[0]==suits[4]){
            return "Flush";
        }
        int num = INT_MIN;
        for(int i = 0; i<ranks.size(); i++){
            int temp = 1;
            for(int j = i+1; j<ranks.size(); j++){
                if(ranks[i]==ranks[j]){
                    temp+=1;
                }
                
            }
            num = max(num,temp);
        }
        if(num>=3){
            return "Three of a Kind";
        }
        else if(num==2){
            return "Pair";
        }
        return "High Card";
    }
};