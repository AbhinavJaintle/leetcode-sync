class Solution {
public:
    string arrangeWords(string text) {
        stringstream take(text);
        vector<pair<string,int>> arr;
        string ans,word;
        int cnt = 0;
        while(take>>word)arr.push_back({word,cnt++});
        sort(arr.begin(),arr.end(),[&](auto &a,auto &b){
            if(a.first.size() == b.first.size())return a.second <= b.second;
            return a.first.size() <= b.first.size();
        });
        for(auto ele:arr){
            transform(ele.first.begin(),ele.first.end(), ele.first.begin(), ::tolower);
            ans+=ele.first + " ";
        }
        if(ans[0]>='a' and ans[0] <= 'z')ans[0] -=32;
        ans.pop_back();
        return ans;
    }
};