class Solution 
{
    public:
    int findTheLongestSubstring(string s) 
    {
        int result=0;
        int n=s.length();
        int current=0;
        unordered_map<char,int> m;
        m['a']=0;
        m['e']=1;
        m['i']=2;
        m['o']=3;
        m['u']=4;
        int overall[32];
        for(int i=0;i<32;i++)
            overall[i]=-1;
       
        overall[0]=0;
        for(int i=0;i<n;i++)
        {
            if(m.find(s[i])!=m.end())
                current=current^((int)pow(2,m[s[i]]));
        
            if(overall[current]!=-1)
                result=max(result,i+1-overall[current]);
            else
                overall[current]=i+1;
        }
        return result;
    }
};