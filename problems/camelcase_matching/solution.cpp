class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool>v;
        for(auto&i:queries){
            int index=0;
            for(auto&j:i){
                if(index<pattern.length()){
                    if(j==pattern[index]){
                        index++;
                    }
                    else{
                       if(j<91){
                            index=0;
                            break;
                        } 
                    }
                }
                else{
                    if(j<91){
                        index=0;
                        break;
                    }
                }
            }
            v.push_back(index==pattern.length());
        }
        return v;
    }
};