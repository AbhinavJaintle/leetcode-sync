class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans;
        unordered_map<string,string> m;
        for(auto&i:knowledge){
            m[i[0]]=i[1];
        }
        for(int i = 0; i<s.length(); i++){
            if(s[i]=='('){
                i++;
                string temp;
                while(s[i]!=')'){
                    temp.push_back(s[i++]);
                }
                if(m[temp]!="") ans+=m[temp];
                else ans.push_back('?');
            }
            else ans.push_back(s[i]);
        }
        return ans;
    }
};