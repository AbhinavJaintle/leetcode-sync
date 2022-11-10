class Solution {
public:
  int dp[301][5][6][5][6][2];
   int helper(string &word,int start,int prevXfing1,int prevYfing1,int prevXFing2,int prevYFing2,bool finger2,unordered_map<char,pair<int,int>>&mp){
       if(start==word.length()) return 0;
     if(dp[start][prevXfing1][prevYfing1][prevXFing2][prevYFing2][finger2]!=-1) 
       return dp[start][prevXfing1][prevYfing1][prevXFing2][prevYFing2][finger2];
      int currstartX= mp[word[start]].first; 
     int currstartY= mp[word[start]].second; 
     if(finger2){
        int op1= abs(currstartX-prevXfing1)+abs(currstartY-prevYfing1)+helper(word,start+1,currstartX,currstartY,prevXFing2,prevYFing2,finger2,mp);
        int op2= abs(currstartX-prevXFing2)+abs(currstartY-prevYFing2)+ helper(word,start+1,prevXfing1,prevYfing1,currstartX,currstartY,finger2,mp);
       return dp[start][prevXfing1][prevYfing1][prevXFing2][prevYFing2][finger2]=min(op1,op2);
        }
      else{
          int op1= abs(currstartX-prevXfing1)+abs(currstartY-prevYfing1)+helper(word,start+1,currstartX,currstartY,prevXFing2,prevYFing2,finger2,mp);
        int op2= helper(word,start+1,prevXfing1,prevYfing1,currstartX,currstartY,true,mp);
        return dp[start][prevXfing1][prevYfing1][prevXFing2][prevYFing2][finger2]=min(op1,op2);
      }
    
   
      
   }
    int minimumDistance(string word) {
       for(int i=0;i<word.length();i++) word[i]=tolower(word[i]);
     // cout<<word;
        unordered_map<char,pair<int,int>>mp;
        mp['a']={0,0};
      mp['b']={0,1};
      mp['c']={0,2};
      mp['d']={0,3};mp['e']={0,4};mp['f']={0,5};
      mp['g']={1,0};mp['h']={1,1};
      mp['i']={1,2};mp['j']={1,3};mp['k']={1,4};mp['l']={1,5};
      mp['m']={2,0};mp['n']={2,1};mp['o']={2,2};mp['p']={2,3};mp['q']={2,4};
      mp['r']={2,5};mp['s']={3,0};mp['t']={3,1};mp['u']={3,2};mp['v']={3,3};
      mp['w']={3,4};mp['x']={3,5};mp['y']={4,0};
      mp['z']={4,1};
      memset(dp,-1,sizeof(dp));
        return helper(word,1,mp[word[0]].first,mp[word[0]].second,0,0,false,mp);
    }
};