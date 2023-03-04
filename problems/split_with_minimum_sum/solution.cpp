class Solution {
public:
    int splitNum(int num) {
        string temp=to_string(num);
        bool flag=true;
        string num1;
        string num2;
        sort(temp.begin(),temp.end());
        for(auto&i:temp){
            if(flag)num1.push_back(i);
            else num2.push_back(i);
            flag=!flag;
        }
        return stoi(num1)+stoi(num2);
    }
};