class Solution {
public:
    int maximizeWin(vector<int>& A, int k) {
        int ans = 0,n = A.size();
        //pointer to start of sliding window
        int start = 0 ;
        //variable for storing current count
        int count = 0;
        //end_limit of range
        int end = A[0] + k;
        
        int cur_val = 0;
        vector<int>pref(n),suff(n);

        for(int i=0;i<n;++i){
            int cur = A[i];
            //if current element is in range we increment our count
            if(cur<= end){
                count++;
            }
            else{
                //else we move the start of our window to right until current 
                //element is in range 
                while(cur>end){
                    start++;
                    end = A[start]+k;
                    count--;
                }
                count++;
            }
            cur_val = max(cur_val,count);
            //pref[i] -- it store the max count from [0,i]
            pref[i] = cur_val;
        }
        
        //now for suffix 
        start = n-1;
        end = A[n-1] - k;
        count = 0,cur_val = 0;

        for(int i=n-1;i>=0;--i){
            int cur = A[i];
            //if current value is in range    
            if(cur>=end){
                count++;
            }
            else{
                //else we move the start of our window to left until current 
                //element is in range (we are starting form end and moving to first so left movment)
                while(cur<end){
                    start--;
                    end = A[start]-k;
                    count--;
                }
                count++;
                 
            }
            cur_val = max(cur_val,count);
            //suff[i] --  it store the max count from [i,n-1]
            suff[i] = cur_val;
        }
        
        for(int i=0;i<n;++i){
            int sum = pref[i];
            if((i+1)<n)sum += suff[i+1];

            //the max sum from [0,i] + [i+1,n-1]
            ans = max(ans,sum);
        }
      
        
        return ans;
    }
};