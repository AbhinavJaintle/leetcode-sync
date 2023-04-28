class Solution {
public:
    vector<string> printVertically(string s) {
        string s1=s;
        stringstream ss(s);
        string temp;
        int maxi=0;
        while(ss>>temp){
            int n = temp.length();
            maxi=max(maxi,n);
        }
        vector<string> ans(maxi);
        stringstream ss1(s1);
        string temp1;
        while(ss1>>temp1){
            for(int i = 0; i<temp1.length(); i++){
                ans[i].push_back(temp1[i]);
            }
            for(int i = temp1.length(); i<maxi; i++){
                ans[i].push_back(' ');
            }
        }
        for(auto&i:ans){
            int index=i.length()-1;
            while(i[index]==' '){i.pop_back();index--;}
        }
        return ans;
    }
};