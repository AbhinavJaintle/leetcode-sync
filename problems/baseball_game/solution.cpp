class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> s;
        for(int i = 0; i<ops.size();i++){
            if(ops[i]=="C"){
                s.pop();
            }
            else if(ops[i]=="D"){
                s.push(s.top()*2);
            }
            else if(ops[i]=="+"){
                int x = s.top();
                s.pop();
                int y = s.top();
                int n = x+y;
                s.push(x);
                s.push(n);
            }
            else{
                int num;
                stringstream ss;  
                ss << ops[i];  
                ss >> num;  
                s.push(num);
            }
        }
        int ans = 0;
        while(!s.empty()){
            ans+=s.top();
            s.pop();
        }
        return ans;
    }
};