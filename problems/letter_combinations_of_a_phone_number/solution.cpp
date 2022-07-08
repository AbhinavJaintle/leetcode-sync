class Solution {
public:
    vector<string> letterCombinations(string digits)
{
    int n = digits.length();
    vector<string> v;
    map<char, vector<string>> m;
    string nums = "23456789";
    m[nums[0]] = {"a","b","c"};
    m[nums[1]] = {"d","e","f"};
    m[nums[2]] = {"g","h","i"};
    m[nums[3]] = {"j","k","l"};
    m[nums[4]] = {"m","n","o"};
    m[nums[5]] = {"p","q","r","s"};
    m[nums[6]] = {"t","u","v"};
    m[nums[7]] = {"w","x","y","z"}; 
    if(n==0){
        return {};
    }
    if(n==1){
        return m[digits[0]];
    }
    for(int j = 0; j<m[digits[0]].size(); j++){
            v.push_back(m[digits[0]][j]);
        }
    vector<string> temp;
    for(int i = 1; i<n;i++){
        for(int j = 0; j<m[digits[i]].size(); j++){
            for(int k = 0; k<v.size(); k++){
                
                temp.push_back(v[k]+m[digits[i]][j]);
            }
        }
        v = temp;
    }
    vector<string> ans;
    for(int b = 0; b<v.size(); b++){
        if(v[b].length()==n){
            ans.push_back(v[b]);
        }
    }
    
    return ans;
}
};