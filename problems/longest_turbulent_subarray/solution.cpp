class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int sum=1;
        for(int i = 0; i<arr.size()-1; i++){
            int temp=1;
            char prev=arr[i]<arr[i+1]?'l':'g';
            int curr=i;
            int j = i+1;
            while(j<arr.size()){
                if(prev=='l'&&arr[j]>arr[curr]){
                    temp++;
                    prev='g';
                }
                else if(prev=='g'&&arr[j]<arr[curr]){
                    temp++;
                    prev='l';
                }
                else{
                    if(curr!=i) i=curr-1;
                    break;
                }
                curr=j;
                j++;
            }
            sum=max(temp,sum);
        }
        return sum;
    }
};