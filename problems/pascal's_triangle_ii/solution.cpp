class Solution {
public:
    vector<int> getRow(int n) {
        vector<int> vec(n+1, 1);
        long long int temp = 1;
        for(int i = 1; i < n; i++) {
            temp = temp * (n-i+1) / i;  //nCr
            vec[i] = temp;
        } return vec;
    }
};