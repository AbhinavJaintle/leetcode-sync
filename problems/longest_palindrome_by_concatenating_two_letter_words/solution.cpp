class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int flag = 0;
        map<string,int>m;
        int count=0;
        for(auto&i:words){
            
            if(i[0]==i[1]){
                if(m[i]>0){
                    count++;
                    flag--;
                    m[i]-=1;
                }
                else{
                    flag++;
                    m[i]+=1;
                }
            }
            else{
            m[i]+=1;
            string temp;
            temp.push_back(i[1]);
            temp.push_back(i[0]);
            if(m[temp]>0){
                count++;
                m[temp]--;
                m[i]--;
            }
            }
            
        }
        if(flag>0) flag=1;
        return 4*count+2*flag;
    }
};