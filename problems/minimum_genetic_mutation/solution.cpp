class Solution {
public:
    bool check(string s1, string s2){
        if(s1.length()!=s2.length()){
            return false;
        }
        int flag = 0;
        for(int i=0; i<s1.length(); i++){
            if(s1[i]!=s2[i]){
                flag++;
            }
        }
        return (flag==1);
    }
    int minMutation(string start, string end, vector<string>& bank) {
        map<string,vector<string>> m;
        if(bank.size()==0){
            return -1;
        }
        for(auto&i:bank){
          if(check(start,i)){
            m[start].push_back(i);
            m[i].push_back(start);
          }
        }
        for(int i = 0; i<bank.size()-1; i++){
            for(int j = i+1; j<bank.size(); j++){
                if(check(bank[i],bank[j])){
                    m[bank[i]].push_back(bank[j]);
                    m[bank[j]].push_back(bank[i]);
                }
            }
        }
        queue<pair<string,int>> q;
        q.push({start,0});
        map<string,int> vis;
        while(!q.empty()){
            string temp = q.front().first;
            int mut = q.front().second;
            q.pop();
            if(temp==end){
                return mut;
            }
            vis[temp]++;
            for(auto&i:m[temp]){
                if(vis[i]==0){
                    q.push({i,mut+1});
                }
            }
        }
        return -1;
    }
};