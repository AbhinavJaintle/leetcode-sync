class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        map<char,int> m;
        for(int i = 0; i<magazine.length(); i++){
            m[magazine[i]] += 1;
        }
        for(int i = 0; i<ransomNote.length();i++){
            if(!m[ransomNote[i]]){
                return false;
            }
            m[ransomNote[i]]--;
        }
        return true;
    }
};