class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> vis;
        unordered_map<int,int> m;
        for(auto&i:nums){
            m[i]++;
        }
        int maxi = 0;
        for(auto&i:nums){
            int temp = i;
            int count = 0;
            while(m[temp]!=0){
                if(vis[temp]!=0){
                    count+=vis[temp];
                    break;
                }
                count++;
                temp++;
            }
            vis[i]=count;
            maxi=max(maxi,count);
        }
        return maxi;
    }
};