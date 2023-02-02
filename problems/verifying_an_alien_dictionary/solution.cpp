class Solution {
    unordered_map<char,int> m;
public:
    bool comp(string w1, string w2){
        for(int i = 0; i<min(w1.length(),w2.length()); i++){
            if(m[w1[i]]>m[w2[i]])return false;
            if(m[w1[i]]<m[w2[i]])return true;
        }
        return w1.length()<=w2.length();
    }
    bool isAlienSorted(vector<string>& words, string order) {
        m.clear();
        int index=1;
        for(auto&i:order){
            m[i]+=index;
            index++;
        }
        for(int i = 0; i<words.size()-1; i++){
            if(!comp(words[i],words[i+1]))return false;
        }
        return true;
    }
};