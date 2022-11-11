class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int curr = 1;
        int i = 1;
        int prev = nums[0];
        while(curr<nums.size()){
            while(curr<nums.size()&&nums[curr]==prev){
                curr++;
            }
            if(curr<nums.size()){
                nums[i]=nums[curr];
                prev = nums[i];
                i++;
            }
            
            
            curr++;
        }
        return i;
    }
};