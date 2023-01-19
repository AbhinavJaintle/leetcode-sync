class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int index=1;
        int i=0;
        while(k){
            if(i<arr.size()&&arr[i]!=index){
                k--;
            }
            else{
                if(i>=arr.size())k--;
                i++;
            }
            index++;
        }
        return index-1;
    }
};