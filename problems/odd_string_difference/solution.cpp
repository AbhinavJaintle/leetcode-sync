class Solution {
public:
    string oddString(vector<string>& words) {
        map<vector<int>, int> m1;
        map<vector<int>, string> m2;
        int n = words[0].length();
        for(auto&i:words){
            vector<int> temp(n-1);
            for(int j = 1; j<n; j++){
                temp[j-1]=i[j]-i[j-1];
            }
            m2[temp]=i;
            m1[temp]++;
        }
        for(auto&i:m1){
            if(i.second==1){
                return m2[i.first];
            }
        }
        return "";
    }
};