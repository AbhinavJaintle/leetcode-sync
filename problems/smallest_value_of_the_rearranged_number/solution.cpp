class Solution {
public:
    long long smallestNumber(long long num) {
        if(num==0){
            return 0;
        }
        string temp = to_string(num);
        if(temp[0]!='-'){
            vector<int> v;
            int mini= 9;
            for(int i = 0; i<temp.length(); i++){
                mini = (temp[i]-'0'!=0) ? min(mini,temp[i]-'0'):mini;
                v.push_back(temp[i]-'0');
            }
            string ans;
            ans += to_string(mini);
            auto it = find(v.begin(),v.end(),mini);
            if (it != v.end()) {
                v.erase(it);
            }
            sort(v.begin(),v.end());
            for(auto&i:v){
                ans+=to_string(i);
            }
            return stoll(ans);       
        }
        else{
            vector<int> v;
            for(int i = 1; i<temp.length(); i++){
                v.push_back(temp[i]-'0');
            }
            string ans;
            sort(v.begin(),v.end(),greater<int>());
            ans+="-";
            for(auto&i:v){
                ans+=to_string(i);
            }
            return stoll(ans);
        }
        return 0;
    }
};