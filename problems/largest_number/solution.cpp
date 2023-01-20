class Solution {
public:
    static bool mysort(int a, int b){
        string t1 = to_string(a);
        string t2 = to_string(b);
        
        return t1+t2>t2+t1;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),mysort);
        string temp;
        for(auto&i:nums){
            temp+=to_string(i);
        }
        if(temp[0]=='0')return "0";
        return temp;
    }
};