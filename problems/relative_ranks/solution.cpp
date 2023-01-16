class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> temp=score;
        unordered_map<int,int> m;
        sort(temp.begin(),temp.end(),greater<int>());
        for(int i = 0; i<temp.size(); i++){
            m[temp[i]]=i+1;
        }
        vector<string> ans;
        for(auto&i:score){
            if(m[i]==1)ans.push_back("Gold Medal");
            else if(m[i]==2)ans.push_back("Silver Medal");
            else if(m[i]==3)ans.push_back("Bronze Medal");
            else ans.push_back(to_string(m[i]));
        }
        return ans;
    }
};