class Solution {
public:
    int halveArray(vector<int>& nums) {
        priority_queue<double> pq;
        double sum=0;
        for(auto&i:nums){
            pq.push(i);
            sum+=i;
        }
        sum/=2;
        double curr=0;
        int ans=0;
        while(curr<sum){
            double temp=pq.top();
            pq.pop();
            temp/=2;
            curr+=temp;
            pq.push(temp); 
            ans++;
        }
        return ans;
    }
};