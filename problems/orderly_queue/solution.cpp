class Solution {
public:
    string traverse(string s, int k, map<string,int>&m){
        string ans = s;
        if(m[s]!=0){
            return s;
        }
        m[s]++;
        for(int i = 0; i<k; i++){
            string temp = s;
            temp.push_back(temp[i]);
            temp.erase(i,1);
            ans = min(ans,traverse(temp,k,m));
        }
        return ans;
    }
    string orderlyQueue(string s, int k) {
        map<string,int> m;
        if(k>1){
            sort(s.begin(),s.end());
            return s;
        }
        return traverse(s,k,m);
    }
};