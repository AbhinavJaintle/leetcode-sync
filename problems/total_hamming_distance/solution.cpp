class Solution {
public:
    
   int totalHammingDistance(vector<int>& nums) {
        
        int ans = 0 ;       
        for(int i=0;i<32;++i){
            int zeros=0;
            int ones=0;
            for(auto num:nums){
                
                if((num&(1<<i))) ones++;
                else zeros++;
                   
        }
            ans+=zeros*ones; 
        }
        return ans;
    }
};