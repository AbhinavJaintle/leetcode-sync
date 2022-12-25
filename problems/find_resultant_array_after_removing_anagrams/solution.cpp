class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        string prev = words[0];
        vector<string> ans;
        ans.push_back(words[0]);
        sort(prev.begin(),prev.end());
        for(int i = 0; i<words.size(); i++){
            string temp= words[i];
            sort(temp.begin(),temp.end());
            if(temp!=prev){
                ans.push_back(words[i]);
            }
            prev=temp;
        }
        return ans;
    }
};