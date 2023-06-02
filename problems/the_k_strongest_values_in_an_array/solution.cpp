class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        priority_queue<pair<int,int>> pq;
        vector<int> n = arr;
        sort(n.begin(),n.end());
        int med = n[(n.size()-1)/2];
        for(int i= 0; i<arr.size(); i++){
            pq.push({abs(arr[i]-med),arr[i]});
        }
        vector<int> ans;
        while(k){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
        return ans;
    }
};