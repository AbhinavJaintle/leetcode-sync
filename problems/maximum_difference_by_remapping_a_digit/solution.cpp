class Solution {
public:
    int minMaxDifference(int num) {
        string temp = to_string(num);
        string t = temp;
        char ch = temp[0];
        for(auto&i:temp){
            if(i==ch)i='0';
        }
        int op1 = stoi(temp);
        int curr=0;
        while(curr<t.length()&&t[curr]=='9'){
            curr++;
        }
        if(curr==t.length()){
            for(auto&i:t){
                i='9';
            }
        }
        else{
            ch=t[curr];
            for(auto&i:t){
                if(i==ch)i='9';
            }
        }
        
        int op2=stoi(t);
        return op2-op1;
    }
};