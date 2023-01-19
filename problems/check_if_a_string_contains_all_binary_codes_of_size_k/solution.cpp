class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if(s.length()<k)return false;
        unordered_map<string,int> m;
        long long res=0;
        for(int i = 0; i<=s.length()-k; i++){
            string temp = s.substr(i,k);
            if(!m[temp]){
                m[temp]++;
                res++;
            }
        }
        return res==pow(2,k);
    }
};