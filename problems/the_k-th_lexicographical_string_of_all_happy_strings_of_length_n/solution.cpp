class Solution {
    vector<string>v;
public:
    void generateHstring(int n, string curr, vector<char>vals){
        if(n==0){
            v.push_back(curr);
            return;
        }
        
        for(auto&j:vals){
                if(curr==""||j!=curr[curr.length()-1]){
                    curr.push_back(j);
                    generateHstring(n-1,curr,vals);
                    curr.pop_back();
                }
        }
        
    }
    string getHappyString(int n, int k) {
        vector<char> vals = {'a','b','c'};
        string curr = "";
        generateHstring(n,curr,vals);
        if(v.size()<k){
            return "";
        }
        return v[k-1];
    }
};