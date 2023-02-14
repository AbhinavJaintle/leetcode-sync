class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        if(sentence1.length()<sentence2.length())return areSentencesSimilar(sentence2,sentence1);
        stringstream ss1(sentence1);
        stringstream ss2(sentence2);
        vector<string> v1;
        vector<string> v2;
        string words;
        while(ss1>>words){
            v1.push_back(words);
        }
        while(ss2>>words){
            v2.push_back(words);
        }
        int sum=0;
        int index=0;
        while(index<v2.size()&&v2[index]==v1[index]){
            index++;
            sum++;
        }
        index=1;
        while(index<=v2.size()&&v2[v2.size()-index]==v1[v1.size()-index]){
            index++;
            sum++;
        }
        return sum>=v2.size();
    }
};