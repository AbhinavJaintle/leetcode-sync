class Solution {
struct cmp {
    bool operator() (string a, string b) const {
        if(a.length()>b.length()){
            return true;
        }
        else if(b.length()>a.length()){
            return false;
        }
        return a>b;
    }
};
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        
        sort(nums.begin(),nums.end(),cmp());
        return nums[k-1];
    }
};