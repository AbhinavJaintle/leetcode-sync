class Solution {
public:
    int monotone(int index, string high, int n, string curr,int tight){
        if(index==n+1){
            return stoi(curr);
        }
        int maxi=0;
        
        if(tight){
            int temp = high[index]-'0'+1;
            
            while(temp--){
              if(index==0||temp>=curr[curr.length()-1]-'0'){
                tight = (temp==high[index]-'0')?1:0;
                string tp = curr+to_string(temp);
                maxi=max(maxi,monotone(index+1,high,n,tp,tight));
               }
               else{
                   break;
               }
            }
        }
        else{
            int temp = 10;
            while(temp--){
              if(temp>=curr[curr.length()-1]-'0'){
                  string tp = curr+to_string(temp);
                  maxi=max(maxi,monotone(index+1,high,n,tp,tight));
               }
               else{
                   break;
               }
            }
        }
        return maxi;
        
    }
    int monotoneIncreasingDigits(int n) {
        if(n==0){
            return 0;
        }
        if(n==1000000000){
            return 999999999;
        }
        string high = to_string(n);
        int si = log(n)/log(10);
        string s = "";
        return monotone(0,high,si,s,1);
    }
};