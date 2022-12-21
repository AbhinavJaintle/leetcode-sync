class Solution {
    vector<int> v;
    vector<int> temp;
public:
    Solution(vector<int>& nums) {
        v=nums;
    }
    
    vector<int> reset() {
        return v;
    }
    
    vector<int> shuffle() {
        temp = v;
        random_shuffle(temp.begin(), temp.end());
        return temp;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */