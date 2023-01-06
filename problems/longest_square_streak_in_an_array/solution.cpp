class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        unordered_map<int,vector<int>> m;
        sort(nums.begin(),nums.end());
        for(auto&i:nums){
            int t =0;
            int temp=sqrt(i);
            while(temp*temp==i){
                i=temp;
                temp=sqrt(i);
                t++;
            }
            m[i].push_back(t);
        }
        int maxi=0;
        for(auto&i:m){
            int streak=0;
            for(int j = 0; j<i.second.size(); j++){
                if(j==0||i.second[j]-1==i.second[j-1]) streak++;
                
                else if(i.second[j]==i.second[j-1]) continue;
                else{
                    maxi=max(maxi,streak);
                    streak=1;
                }
            }
            maxi=max(maxi,streak);
        }
        return (maxi==1)?-1:maxi;
    }
};