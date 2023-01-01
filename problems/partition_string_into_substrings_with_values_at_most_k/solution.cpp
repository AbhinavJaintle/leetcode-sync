class Solution {
public:
    int minimumPartition(string s, int k) {
        string prev;
        int count =0;
        for(int i = 0; i<s.length(); i++){
            string temp = prev;
            temp.push_back(s[i]);
            if(prev.length()==9||stoi(temp)>k){
                if(temp.length()==1){
                    return -1;
                }
                count++;
                i--;
                prev="";
            }
            else{
                prev=temp;
            }
        }
        if(prev.length()!=0){
            count++;
        }
        return count;
    }
};