class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i = 0; i<arr.size(); i++){
            pq.push({abs(arr[i]-x),i});
        }
        vector<int> ans;
        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            ans.push_back(arr[temp.second]);
            if(ans.size()==k){
                sort(ans.begin(),ans.end());
                return ans;
            }
        }
        return ans;
    }
};