class Solution {
public:
    int addDigits(int num) {
        string temp = to_string(num);
        if(temp.length()==1)return num;
        int index=0;
        int sum=0;
        while(index<temp.length()){
            sum+=temp[index++]-'0';
        }
        return addDigits(sum);
    }
};