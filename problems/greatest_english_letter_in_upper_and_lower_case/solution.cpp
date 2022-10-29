class Solution {
public:
    string greatestLetter(string s) {
        int initial = 95;
        map<int,int> m;
        for(auto&i:s){
            if(i>90){
                m[i]=1;
                if(m[i-32]){
                    initial = max(initial,(int)i);
                }
            }
            else{
                m[i]=1;
                if(m[i+32]){
                    initial = max(initial,i+32);
                }
            }
        }
        if(initial!=95){
            string ans;
            ans.push_back('A'+initial-97);
            return ans;
        }
        return "";
    }
};