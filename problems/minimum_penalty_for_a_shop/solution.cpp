class Solution {
public:
    int bestClosingTime(string customers) {
        vector<int> y(customers.length(),0);
        vector<int> n(customers.length(),0);
        int prev=0;
        for(int i = 0; i<customers.length(); i++){
            if(customers[i]=='N') prev++;
            y[i]=prev;
        }
        prev=0;
        for(int i = customers.length()-1; i>=0; i--){
            if(customers[i]=='Y') prev++;
            n[i]=prev;
        }
        int mini = n[0];
        int index = 0;
        for(int i = 1; i<customers.length(); i++){
            if(mini>y[i-1]+n[i]){ 
                mini=y[i-1]+n[i];
                index=i;
            }
        }
        if(mini>y[customers.length()-1]) index=customers.length();

        return index;
        
    }
};