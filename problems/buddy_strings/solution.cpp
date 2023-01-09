class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size()) return false;
        if(s==goal){
            unordered_map<char,int> m;
            for(auto&i:goal){
                m[i]++;
                if(m[i]==2) return true;
            }
        }
        else{
            int flag=0;
            char temp1;
            char temp2;
            for(int i = 0; i<goal.size(); i++){
                if(goal[i]!=s[i]){ 
                    if(flag>=2) return false;
                    if(flag==1){
                        if(temp1!=goal[i]||temp2!=s[i]) return false;
                        flag++;
                    }
                    else{
                        flag++;
                        temp1=s[i];
                        temp2=goal[i];
                    }
                }
            }
            if(flag==2) return true;
        }
        return false;
    }
};