class Solution {
public:
    static bool mysort(vector<int> a, vector<int> b){
        return a[0]==b[0]?a[1]<b[1]:a[0]<b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> ans(people.size());
        sort(people.begin(),people.end(),mysort);
        unordered_map<int,int> vis;
        for(auto&i:people){
            int index = vis[i[0]]==0?i[1]+1:i[1]+1-vis[i[0]];
            vis[i[0]]++;
            int k =-1;
            while(index>0){
                if(ans[k+1].size()==0){ 
                    index--;
                }
                k++;
            }
            ans[k]=i;
        }
        return ans;
    }
};