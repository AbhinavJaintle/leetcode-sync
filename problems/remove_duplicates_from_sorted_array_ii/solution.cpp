class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index=0;
        int streak=0;
        int prev=INT_MAX;
        for(int i = 0; i<nums.size(); i++){
            if(nums[i]==prev){
                streak++;
                nums[index]=nums[i];
            }
            else{
                streak=1;
                prev=nums[i];
                nums[index]=nums[i];
            }
            if(streak<=2)index++;
        }
        return index;
    }
};