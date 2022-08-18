class Solution {
public:
    int minSetSize(vector<int>& arr) {
        priority_queue<int> pq;
        int count = 1;
        sort(arr.begin(),arr.end());
        for(int i = 1; i<arr.size(); i++){
            if(arr[i]==arr[i-1]){
                count+=1;
            }
            else{
                pq.push(count);
                count = 1;
            }
        }
        if(count!=1){
            pq.push(count);
        }
        int target = arr.size()/2;
        int ans = 0;
        while(target>0){
            target-=pq.top();
            pq.pop();
            ans+=1;
        }
        return ans;
    }
};