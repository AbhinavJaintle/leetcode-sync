class Solution {
public:
    string addBinary(string a, string b) {
        int i,j,carry,x,y;
        i = a.length()-1; // start from the right end of string a
        j = b.length()-1; //start from the right end of string b
        carry = 0;
        string ans;
		
        while(1)
        {
            if(i<0 and j<0) break; // we reached the left end point of both strings, a and b, so stop here
            if(i<0) x = 0;
            else x = a[i] - '0';
            if(j<0) y = 0;
            else y = b[j] - '0';
            int sum = x+y+carry;
            if(sum<2) 
            {
                carry = 0;
                ans += sum + '0';
            }
            else if(sum==2) 
            {
                carry = 1;
                ans += '0';
            }
            else  
            {
             carry = 1;
             ans += '1';
            }
            i--;
            j--;
        }
        if(carry)  ans += carry + '0'; // if the last carry is 1, then add it to ans, else skip
        reverse(ans.begin(), ans.end());
        return ans;
    }
};