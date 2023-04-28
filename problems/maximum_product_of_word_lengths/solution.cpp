class Solution {
public:
    int maxProduct(vector<string>& words) {
        int maxi = 0<<26;
        unordered_map<int,int> m;
        for(int i = 0; i<words.size(); i++){
            int temp = maxi;
            for(auto&j:words[i]){
                int n = 1<<(j-'a'+1);
                temp|=n;
            }
            m[i]=temp;
        }
        int ans=0;
        for(int i = 0; i<words.size(); i++){
            int curr=0;
            for(int j = i+1; j<words.size(); j++){
                if((m[i]|m[j])==(m[i]^m[j])){
                    int t = words[i].length()*words[j].length();
                    curr=max(curr,t);
                }
            }
            ans=max(ans,curr);
        }
        return ans;
    }
};