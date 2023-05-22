class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string,int> m;
        for(int i = 0; i < senders.size(); i++){
            string temp = messages[i];
            stringstream ss(temp);
            string word;
            int w = 0;
            while(ss>>word){
                w++;
            }
            m[senders[i]]+=w;
        }
        int maxi=0;
        string ans = "";
        for(auto&i:m){
            if(i.second>maxi){
                maxi=i.second;
                ans=i.first;
            }
            else if(i.second==maxi){
                ans=max(ans,i.first);
            }
        }
        return ans;
    }
};