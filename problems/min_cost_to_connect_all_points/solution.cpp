class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        unordered_map<int,int> mst;
        unordered_map<int,int> key;
        int sum=0;
        int count=points.size()-1;
        mst[0]++;
        int prev=0;
        while(count){
        
            for(int j =0; j<points.size(); j++){
                if(prev!=j&&mst[j]==0){
                    int temp = abs(points[prev][0]-points[j][0])+abs(points[prev][1]-points[j][1]);
                    if(key[j]==0||key[j]>temp){
                        key[j]=temp;
                    }
                }
            }
        
            int mini = INT_MAX;
            int index;
            for(auto&i:key){
                if(mst[i.first]==0){
                    if(i.second<mini){
                        mini=i.second;
                        index=i.first;
                    }
                }
            }
            sum+=mini;
            mst[index]++;
            prev=index;
            count--;
        }
        return sum;
    }
};