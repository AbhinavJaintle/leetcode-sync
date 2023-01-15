class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int prev=0;
        int sum=0;
        int index=1;
        for(auto&i:arr){
            i+=prev;
            prev=i;
            if(index%2!=0)sum+=prev;
            index++;
        }
        
        for(int i = 0; i<arr.size(); i++){
            for(int j = i+1; j<arr.size(); j+=2){
                sum+=arr[j]-arr[i];
            }
        }
        return sum;
    }
};