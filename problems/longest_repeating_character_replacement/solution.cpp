class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxi = 0;
        int prev=-1;
        int count=0;
        int l = 0;
        char curr = s[0];
        bool flag=false;

        for(int i = 0; i<s.length(); i++){
            if(s[i]==curr){
                count++;
            }
            else{
                if(!flag){
                    flag=true;
                    prev=i;
                }
                count++; 
                l++;
            }
            if(l==k+1){
                count--;
                maxi=max(count,maxi);
                i=prev-1;
                curr=s[i+1];
                count=0;
                l=0;
                flag=false;
            }
        }
        return max(maxi,min(count+k-l,(int)s.length()));
    }
};