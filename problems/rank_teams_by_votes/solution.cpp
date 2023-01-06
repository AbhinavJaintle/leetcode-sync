class Solution {
public:
    static bool mySort(pair<char,vector<int>> a, pair<char,vector<int>> b){
        for(int i = 0; i<a.second.size(); i++){
            if(a.second[i]>b.second[i]) return true;
            else if(a.second[i]<b.second[i]) return false;
        }
        return a.first<b.first;
    }
    string rankTeams(vector<string>& votes) {
        int len=votes[0].size();
        map<char,vector<int>> m;
        vector<int> temp;
        for(auto&i:votes[0]){
            temp.push_back(0);
        }
        for(auto&i:votes[0]){
            m[i]=temp;
        }
        for(auto&i:votes){
            for(int j = 0; j<i.length(); j++){
                m[i[j]][j]++;
            }
        }
        vector<pair<char,vector<int>>> v;
        for(auto&i:m){
            v.push_back({i.first,i.second});
        }
        sort(v.begin(),v.end(),mySort);
        string ans;
        for(auto&i:v){
            ans.push_back(i.first);
        }
        return ans;
    }
};