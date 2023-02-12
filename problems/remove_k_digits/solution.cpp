class Solution {
public:
    string removeKdigits(string num, int k) {
        bool flag=true;
        if(k==0){
            int index=0;
            while(num.length()-1!=index&&num[index]=='0'){
                index++;
            }
            return num.substr(index,num.length()-index);
        }
        if(num.length()==k)return"0";
        for(int i = 0; i<num.length()-1; i++){
            if(num[i]>num[i+1]){
                num[i]='#';
                flag=false;
                break;
            }
        }
        if(flag){
            string t = num.substr(0,num.length()-k);
            int index=0;
            while(t.length()-1!=index&&t[index]=='0'){
                index++;
            }
            return t.substr(index,t.length()-index);
        }
        string temp;
        for(auto&i:num){
            if(i!='#')temp.push_back(i);
        }
        return removeKdigits(temp,k-1);
    }
};