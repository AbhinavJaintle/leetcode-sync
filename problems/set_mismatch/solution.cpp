class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int,int> m;
        for(int i = 0; i<nums.size(); i++){
            m[nums[i]]++;
        }
        int f;
        int s;
        for(int i = 1; i<nums.size()+1; i++){
            if(m[i]==2){
                f=i;
            }
            if(m[i]==0){
                s=i;
            }
        }
        return {f,s};
    }
};