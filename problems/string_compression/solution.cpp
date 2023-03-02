class Solution {
public:
    int compress(vector<char>& chars) {
        if(chars.size()==1)return 1;
        string temp;
        char prev=chars[0];
        int curr=1;
        for(int i = 1; i<chars.size()-1; i++){
            if(chars[i]==prev){
                curr++;
            }
            else{
                temp.push_back(prev);
                if(curr!=1)temp+=to_string(curr);
                curr=1;
                prev=chars[i];
            }
        }
        if(chars[chars.size()-1]==prev){
            curr++;
            temp.push_back(prev);
            temp+=to_string(curr);
        }
        else{
            temp.push_back(prev);
            if(curr!=1)temp+=to_string(curr);
            temp.push_back(chars[chars.size()-1]);
        }
        for(int i = 0; i<temp.length(); i++){
            chars[i]=temp[i];
        }
        return temp.length();
    }
};