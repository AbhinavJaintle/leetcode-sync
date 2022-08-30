
class Solution {
public:
    int minSwapsCouples(vector<int>& row)  //couples me smaller no. is even
    {
        int cnt = 0;
        int n = row.size();
        int curr, to_find, temp;
        
        for(int i=0; i<n-1; i+=2)
        {
            curr = row[i];
            if(curr%2)           //if odd then find odd-1
                to_find = curr-1;
            else                 //if even then find even+1
                to_find = curr+1;
            
            for(int j=i+1; j<n; j++)   // because row before i have correct partners so search after i
            {
                if(row[j] == to_find and j!=i+1)   //swap
                {
                    cnt++;
                    
                    temp = row[j];
                    row[j] = row[i+1];
                    row[i+1] = temp;
                    
                    break;
                }
            }
        }
        
        return cnt;
    }
};