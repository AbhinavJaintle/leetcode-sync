class Solution {
public:
    vector<string> v;
    
    bool isValid(string a){
        stack <char> s;
        for(int i = 0; i<a.length(); i++){
            if(s.empty()&&a[i]==')'){
                return false;
            }
            if(a[i]=='('){
                s.push(a[i]);
            }
            else{
                s.pop();
            }
        }
        if(s.empty()){
            return true;
        }
        return false;
    }
    
    bool parents(string ans, int n){
        if(n==0){
            if(isValid(ans)){
                v.push_back(ans);
                return true;
            }
            else{
                return false;
            }
        }
        bool x = parents(ans+"((",n-1);
        bool y = parents(ans+"))",n-1);
        bool z = parents(ans+"()",n-1);
        bool w = parents(ans+")(",n-1);
        if(x||y||z||w){
            return true;
        }
        
        return false;
    }
    
    vector<string> generateParenthesis(int n) {
        v.clear();
        string e = "";
        parents(e,n);
        return v;
    }
};