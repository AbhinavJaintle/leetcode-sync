class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        vector<vector<char>>v(rows,vector<char>(encodedText.length()/rows));
        int t = 0;
        int c = 0;
        for(auto&i:encodedText){
            if(t==v[0].size()){
                t=0;
                c++;
            }
            v[c][t]=i;
            t++;
        }
        string temp;
        for(int i = 0; i<v[0].size(); i++){
            for(int j = 0; j<v.size()&&i+j<v[0].size(); j++){
                temp.push_back(v[j][i+j]);
            }
        }
        while(temp.length()&&temp.back()==' '){
            temp.pop_back();
        }
        return temp;
    }
};