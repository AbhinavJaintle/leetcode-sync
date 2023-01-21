class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> v;
        for(int i = 0; i<nums1.size(); i++){
            v.push_back({nums2[i],nums1[i]});
        }
        sort(v.begin(),v.end(),greater<pair<int,int>>());
        int index=0;
        priority_queue<int,vector<int>, greater<int>> mini;
        long long sum=0;
        while(index<k){
            mini.push(v[index].second);
            sum+=v[index].second;
            index++;
        }
        long long ans = sum*v[index-1].first;
        while(index<v.size()){
            int temp = mini.top();
            mini.pop();
            sum-=temp;
            sum+=v[index].second;
            mini.push(v[index].second);
            ans=max(ans,sum*v[index].first);
            index++;
        }
        return ans;
    }
};