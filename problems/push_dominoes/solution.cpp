class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        vector<int>left(n,-1*1e6);
        vector<int>right(n,1e6);
        int temp = -1*1e6;
        for(int i = 0; i<n; i++){
            if(dominoes[i]=='R'){
                temp = i;
            }
            else if(dominoes[i]=='L'){
                temp = -1*1e6;
            }
            if(dominoes[i]=='.'){
                left[i]=temp;
            }
        }
        int temp2 = 1e6;
        for(int i = n-1; i>=0; i--){
            if(dominoes[i]=='L'){
                temp2 = i;
            }
            else if(dominoes[i]=='R'){
                temp2=1e6;
            }
            if(dominoes[i]=='.'){
                right[i]=temp2;
            }
        }
        string ans;
        for(int i = 0; i<n; i++){
            if(dominoes[i]=='.'){
                int t = min(i-left[i],right[i]-i);
                if(t>1e5){
                    ans.push_back('.');
                }
                else{
                    if(i-left[i]==right[i]-i){
                        ans.push_back('.');
                    }
                    else if(i-left[i]>right[i]-i){
                        ans.push_back('L');
                    }
                    else{
                        ans.push_back('R');
                    }
                }
            }
            else{
                ans.push_back(dominoes[i]);
            }
        }
        return ans;
    }
};