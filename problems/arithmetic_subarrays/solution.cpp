class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans;
        for(int i = 0; i<l.size(); i++){
            int s = l[i];
            int e = r[i];
            if(e-s+1<2){
                ans.push_back(false);
                continue;
            }
            vector<int> temp;
            for(int j = s; j<=e; j++){
                temp.push_back(nums[j]);
            }
            sort(temp.begin(),temp.end());
            int diff = temp[1]-temp[0];
            bool flag=true;
            for(int j = 1; j<temp.size(); j++){
                if(temp[j]-temp[j-1]!=diff){
                    flag=false;
                    break;
                }
            }
            ans.push_back(flag);
        }
        return ans;
    }
};