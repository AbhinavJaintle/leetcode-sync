class Solution {
    vector<string> ans;
    unordered_map<string,int> m;
public:
    void helper(int index, string s, string curr, int dots){
        if(index==s.length())return;
        if(dots==3){
            if(s.length()-index>3)return;
            string temp=s.substr(index,s.length()-index);
            if(temp[0]=='0'&&temp.length()>1)return;
            if(stoi(temp)>255)return;
            else curr+=temp;
            if(!m[curr]){
                m[curr]++;
                ans.push_back(curr);
            }
        }
        string temp;
        temp.push_back(s[index]);
        index++;
        helper(index,s,curr+temp+".",dots+1);
        if(index<s.length()&&s[index-1]!='0'){ 
            temp.push_back(s[index]);
            helper(index+1,s,curr+temp+".",dots+1);
        }
        index++;
        if(index<s.length()&&s[index-2]!='0'){ 
            temp.push_back(s[index]);
            if(stoi(temp)<=255){ 
                helper(index+1,s,curr+temp+".",dots+1);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        m.clear();
        string curr;
        helper(0,s,curr,0);
        return ans;
    }
};