class Solution {
public:
    string getSmallestString(int n, int k) {
        string temp;
        int sum=0;
        while(temp.length()!=n){
            int curr=1;
            while(26*(n-temp.length()-1)<k-sum-curr){
                curr++;
            }
            sum+=curr;
            temp.push_back('a'+curr-1);
        }
        return temp;
    }
};