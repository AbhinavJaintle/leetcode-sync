class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        map<int,priority_queue<pair<int,int>>> m;
        for(int i = 0; i<nums.size(); i++){
            for(int j = 0; j<nums[i].size(); j++){
                m[i+j].push({i,j});
            }
        }
        vector<int> v;
        for(auto&i:m){
            while(i.second.size()){
                v.push_back(nums[i.second.top().first][i.second.top().second]);
                i.second.pop();
            }
        }
        return v;
    }
};