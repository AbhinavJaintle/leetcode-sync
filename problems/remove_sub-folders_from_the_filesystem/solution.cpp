class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        vector<string> ans;
        sort(folder.begin(),folder.end());
        unordered_map<string,int> m;
        for(int i =0; i<folder.size(); i++){
            string temp = "/";
            int j=1;
            bool flag=true;
            while(temp.length()<folder[i].size()){
                while(j<folder[i].size()&&folder[i][j]!='/'){
                    temp.push_back(folder[i][j]);
                    j++;
                }
                if(m[temp]!=0){
                    flag=false;
                    break;
                }
                temp.push_back('/');
                j++;
            }
            temp.pop_back();
            if(flag&&m[temp]==0){
                m[temp]++;
                ans.push_back(temp);
            }
        }
        return ans;
    }
};