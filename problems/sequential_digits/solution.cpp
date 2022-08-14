class Solution {
public:
    
    vector<string> string_ans;
    
    void f(int idx, string curr, int prev, string &num, bool tight){
        
        if(idx==num.size()){
            string_ans.push_back(curr);
            return;
        }
        
        int dig = prev+1;
        int dig_max = num[idx]-'0';
        
        if(prev>0){
            if(tight){
                if(dig<=9 && dig<=dig_max)
                    f(idx+1,curr+to_string(dig),dig,num,dig==dig_max);
            }else{
                if(dig<=9)
                    f(idx+1,curr + to_string(dig), dig, num, false);
            }
        }else{
            if(tight){
                for(int dig=0;dig<=dig_max;dig++){
                    f(idx+1,curr+to_string(dig),dig,num,dig==dig_max);
                }
            }else{
                for(int dig=0;dig<=9;dig++){
                    f(idx+1,curr+to_string(dig),dig,num,false);
                }
            }
        }
        
    }
    
    vector<int> sequentialDigits(int low, int high) {
        
        string_ans.clear();
        string num = to_string(high);
        f(0,"",0,num,1);
        
        vector<int> int_ans;
        
        for(auto x : string_ans){
            int val = stoi(x);
            if(val>=low) int_ans.push_back(val);
        }
        
        return int_ans;
    }
};