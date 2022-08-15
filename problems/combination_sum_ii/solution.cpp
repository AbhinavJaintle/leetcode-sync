class Solution {
    vector<vector<int>> ans;
    map<vector<int>,int> m;
public:
    void comb(vector<int> candidates, int target, vector<int> temp,int index,int curr,vector<vector<int>>& ans,int prev){
        
        if(index<candidates.size()+1&&curr==target){
          
          if(!m[temp]){
             m[temp]+=1;
             ans.push_back(temp);
          }
            
          return;
        }
        if(curr>target||index>candidates.size()-1){
            return;
        }

        temp.push_back(candidates[index]);
        comb(candidates,target,temp,index+1,curr+candidates[index],ans,candidates[index]);
        if(!temp.size()||prev!=candidates[index]){
            temp.pop_back();
            comb(candidates,target,temp,index+1,curr,ans,prev);
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        ans.clear();
        m.clear();
        vector<int> temp;
        sort(candidates.begin(),candidates.end());
        comb(candidates,target,temp,0,0,ans,-1);
        return ans;
    
    }
};