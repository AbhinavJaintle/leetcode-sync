class Solution {
public:
    int waysToSplitArray(vector<int>& t) {
        long long prev=0;
        long long temp=0;
        vector<long long> nums;
        for(auto&i:t){
            temp=i+prev;
            nums.push_back(temp);
            prev=temp;
        }
        int count=0;
        for(int i = 0; i<nums.size()-1; i++){
            if(nums[i]>=nums[nums.size()-1]-nums[i])count++;
        }
        return count;
    }
};