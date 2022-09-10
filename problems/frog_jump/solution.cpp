class Solution {
    
    unordered_map<int, bool> mp;
    map<pair<int, int> , bool> dp;
    int lastpos;
    
    bool Solve(vector<int>& stones, int pos , int k)
    {
        
        // IF We are at pos which is greater than lastpos return false
        // we dont need to check further 
        // or if we have came back to pos  with k== 0 that means we cant go ahead return false;
        if(pos > lastpos || pos<0 || k == 0)
            return false;
        // Base Condition
        if(pos == lastpos)
            return true;
        
        // If we are at some position which is not memoized we will return false;
        if(!mp[pos])
            return false;
        
        if(dp.find({pos,k}) != dp.end())
            return dp[{pos,k}];
        
        bool op1 = Solve(stones, pos+k, k);
        
        bool op2 = Solve(stones, pos+k+1, k+1);
        
        bool op3 = Solve(stones, pos+k-1, k-1);
        
        return dp[{pos,k}] = op1 || op2 || op3;
    }
    
public:
    bool canCross(vector<int>& stones) {
        
        // Memoizing all valid positions
        lastpos = stones.back();
        for(auto i : stones)
            mp[i] = true;

        // We will start from pos1 with k = 1
        return Solve(stones, 1, 1);
    }
};