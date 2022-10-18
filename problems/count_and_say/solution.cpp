class Solution {
public:
    string countAndSay(int n) {
        if(n==1){
            return "1";
        }
        string num = countAndSay(n-1);
        string temp;
        int count=1;
        char curr = num[0];
        for(int i = 1; i<num.length(); i++){
            if(num[i]==curr){
                count++;
            }
            else{
                temp+=to_string(count);
                temp.push_back(curr);
                curr=num[i];
                count=1;
            }
        }
        temp+=to_string(count);
        temp.push_back(curr);
        return temp;
    }
};