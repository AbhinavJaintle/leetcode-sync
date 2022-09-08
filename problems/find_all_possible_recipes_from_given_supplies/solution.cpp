class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n=recipes.size();
        vector<int>in(n,0);
        set<string>st;
        for(string s:supplies)st.insert(s);
        unordered_map<string,vector<int>>adj;
        queue<string>q;
         
        for(int i=0;i<n;i++){
            for(string s:ingredients[i]){
                if(st.find(s)==st.end()){
                    in[i]++;
                    adj[s].push_back(i);
                }
            }
            if(in[i]==0)q.push(recipes[i]);
        } 
         
        vector<string>ans;
        while(!q.empty()){
            string curr=q.front();
            ans.push_back(curr);
             
            for(int i:adj[curr]){
                in[i]--;
                if(in[i]==0){
                    q.push(recipes[i]);
                }
            }
            q.pop();
        }
        return ans;
    }
};