class Solution {
public:
    int romanToInt(string s) {
        map<char,int> m;
        m.insert({'I',1});
        m.insert({'V',5});
        m.insert({'X',10});
        m.insert({'L',50});
        m.insert({'C',100});
        m.insert({'D',500});
        m.insert({'M',1000});
        int sum = 0;
        for(int i = 0; i<s.length();i++){
            if((i!=s.length()-1)&&s[i]=='I'&&(s[i+1]=='V'||s[i+1]=='X')){
                sum+=m[s[i+1]]-m[s[i]];
                i++;
            }
            else if((i!=s.length()-1)&&s[i]=='X'&&(s[i+1]=='L'||s[i+1]=='C')){
                sum+=m[s[i+1]]-m[s[i]];
                i++;
            }
            else if((i!=s.length()-1)&&s[i]=='C'&&(s[i+1]=='D'||s[i+1]=='M')){
                sum+=m[s[i+1]]-m[s[i]];
                i++;
            }
            else{
                sum+=m[s[i]];
            }
        }
        return sum;
        
    }
};