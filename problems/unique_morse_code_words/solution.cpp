class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string arr[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        int count = 0;
        map<string,int> m;
        for(int i = 0; i<words.size();i++){
            string temp = "";
            for(int j =0; j<words[i].length();j++){
                temp+=arr[words[i][j]-'a'];
            }
            if(m[temp]==0){
                count++;
                m[temp]=1;
            }
            
        }
        return count;
    }
};