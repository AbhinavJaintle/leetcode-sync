class Solution {
public:
    bool check(string a, string b){
        int n = a.length();
        int m = b.length();
        for(int i = 0; i<n-m+1; i++){
            if(a.substr(i,m)==b){
                return true;
            }
        }
        return false;
    }
    int repeatedStringMatch(string a, string b) {
        int n = a.length();
        int m = b.length();
        if(m==0){
            return 0;
        }
        if(m<n){
            if(check(a,b)){
                return 1;
            }
            a+=a;
            if(check(a,b)){
                return 2;
            }
        }
        int k = m/n;
        string temp = a;
        for(int i = 0; i<k-1; i++){
            a+=temp;
        }
        if(a==b){
            return k;
        }
        k++;
        a+=temp;
        if(check(a,b)){
            return k;
        }
        k++;
        a+=temp;
        if(check(a,b)){
            return k;
        }
        return -1;
    }
};