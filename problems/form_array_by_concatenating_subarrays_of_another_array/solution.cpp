class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int start = 0;
        for(auto&i:groups){
            bool flag=false;
            for(int j = start; j<nums.size()-i.size()+1; j++){
                vector<int>::iterator first = nums.begin()+j;
                vector<int>::iterator last = nums.begin()+j+i.size();
                vector<int> temp(first,last);
                if(temp==i){
                    flag=true;
                    start=j+i.size();
                    break;
                }
            }
            if(!flag)return false;
        }
        return true;
    }
};