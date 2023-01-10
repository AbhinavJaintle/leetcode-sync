class Solution {
public:
    int closetTarget(vector<string>& words, string target, int startIndex) {
        vector<int> index;
        for(int i = 0; i<words.size(); i++){
            if(words[i]==target){
                index.push_back(i);
            }
        }
        if(index.size()==0) return -1;
        unsigned long mini = INT_MAX;
        for(auto&i:index){
            mini=min({mini,(startIndex-i+words.size())%words.size(),(i+words.size()-startIndex)%words.size()});
        }
        return (int)mini;
    }
};