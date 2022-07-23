class Solution {
public:
    long long int fibonacci(long long int n){
        long long int temp = 0;
        while(n!=0){
            temp+=n;
            n--;
        }
        return temp;
    }
    
    long long zeroFilledSubarray(vector<int>& nums) {
        long long int streak = 0;
        vector<long long int> ans;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]==0){
                    streak+=1;
                }
            else{
                    ans.push_back(streak);
                    streak = 0;
                }
        }
        if(streak!=0){
            ans.push_back(streak);
        }
        long long int out = 0;
        for(int j = 0; j<ans.size(); j++){
            out+=fibonacci(ans[j]);
        }
        return out;
    }
};